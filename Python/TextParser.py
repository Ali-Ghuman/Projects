import sys
import re

class Node:  #make a node class to allow the creation of a binary search tree 
    def __init__(self, symbol, value1, value2 = None): 
        self.symbol = symbol       #the nonterminal that value1 and value2 make up 
        self.v1 = value1
        self.v2 = value2

def printTree(parentNode):  #recursive function to print the bracketed notation of the parse 
    if parentNode.v2 == None:  #if we reach terminal values, print them as shown  
        return "[" + parentNode.symbol + " " + parentNode.v1 + "]"
    else: 
        return "[" + parentNode.symbol + " " +  printTree(parentNode.v1) + " " + printTree(parentNode.v2) + "]" #recursively call the function to build parse

def printPrettyTree(parentNode): #build textual parse tree 
    parseString = printTree(parentNode) #first obtain the bracketed notation
    stack = ['['] #insert the first element in the stack that will always be present
    tabs = 0 

    print(parseString[0] + parseString[1], end ='') #print the first parts of it that always exist
    for i in range(3, len(parseString)): #loop through the parse string
        if parseString[i] == '[': #if the current item in the index is [ we print a newline, if the top item on the stack
            print('\n', end ='')  #is another [ we increase the amount of tabs 
            if stack[-1] == '[': 
                tabs += 1
                print("   " * tabs, end ='')
            elif stack[-1] == ']':  #if it's a closing bracket, we just add spacing
                print("   " * tabs, end ='')
            stack.append('[')

        if parseString[i] == ']':  #if there are two closing brackets consecutively, we decrease the tabs by 1 and continue
            if stack[-1] == ']':
                tabs -= 1
                print("\n" + "   " * tabs, end ='')
            stack.append(']')

        print(parseString[i], end ='') #prints the current value of the parse
    print("") #end off with a newline


    
def main(): 
    grammarFileName = input("Enter the name of the file containing CNF grammar: ") #read in grammar from input file
    grammarFile = open(grammarFileName, 'r')
    grammar = grammarFile.readlines()
    print("That's some fine lookin' grammar!")

    grammarList = []
    for line in grammar:  #append grammar to list in this fashion: A -> B C => [A, B , C]
        line = line.split()
        if len(line) == 4:
            grammarList.append([line[0], line[2], line[3]])
        else: 
            grammarList.append([line[0], line[2]]) #If no C exists, it will default to null

    while True:  
        sentence = input("Enter a sentence to be parsed (or 'quit' to quit): ")     

        if sentence == 'quit':  #type quit to quit
            print("Sad to see you go, farewell.")
            return 

        tokens = sentence.split()
        tokens = [re.sub(r'[^\w\s]', '', token.lower()) for token in tokens] #remove punctuation from the input sentence
        

        chart = [[ [] for i in range(len(tokens) + 1)] for j in range(len(tokens))] #create a 2d chart of lists, essentially 3D array

        for i, token in enumerate(tokens):  #fill in the diagonal of chart with terminals
            for rule in grammarList: 
                if rule[1] == token: 
                    chart[i][i + 1].append(Node(rule[0], token)) 
        
        for j in range(1, len(tokens) + 1):  #main cky algorithm
            for i in range(j - 2, -1, -1):
                for k in range(i + 1, j): 
                    rowlist = chart[i][k] #list of nodes at given position
                    columnlist = chart[k][j]
                    if len(rowlist) > 0 and len(columnlist) > 0:
                        for rule in grammarList:
                            for rownode in rowlist: 
                                if rownode.symbol == rule[1]:
                                    for columnnode in columnlist: 
                                        if columnnode.symbol == rule[2]:
                                            chart[i][j].append(Node(rule[0], rownode, columnnode)) #if the grammar can be made, set it's children to the constituents of the grammar
                                                                                                   # and it's value as the rule made from the constituents
        nodeList = []
        for value in chart[0][len(tokens)]: #find all the S rules in [0, n] of the chart and append to the nodeList
            if value.symbol == 'S': 
                nodeList.append(value)
        
        if len(nodeList) > 0: #if there are nodes in the list, means we have a valid parse
            print("\nVALID SENTENCE\n")
            valid = False  #set flag to allow users to try again if they type something wrong

            while valid == False: 
                inp = input("Would you like to see a textual parse tree? (y/n): ")
                if inp == 'y':
                    valid = True
                    print("----------------------------------------------------")

                    for i, node in enumerate(nodeList, 1): #For each parse, output parse and it's number
                        print("\nValid parse #" + str(i) + ":\n")
                        printPrettyTree(node) #print the parse tree

                    print("\n\nNumber of valid parses: " + str(len(nodeList)) + '\n') #Give total number of parses
                    print("----------------------------------------------------")

                elif inp == 'n':
                    valid = True
                    print("----------------------------------------------------")

                    for i, node in enumerate(nodeList, 1): 
                        print("\nValid parse #" + str(i) + ":\n")
                        print(printTree(node)) #print bracketed notation

                    print("\n\nNumber of valid parses: " + str(len(nodeList)) + '\n')
                    print("----------------------------------------------------")

                else: 
                    print("Not valid! Retry: ")
        else: 
            print("NO VALID PARSES")




if __name__ == "__main__": 
    main()
