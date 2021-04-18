import sys
import re

class Node: 
    def __init__(self, symbol, value1, value2 = None): 
        self.symbol = symbol 
        self.v1 = value1
        self.v2 = value2

def printTree(parentNode): 
    if parentNode.v2 == None: 
        return "[" + parentNode.symbol + " " + parentNode.v1 + "]"
    else: 
        return "[" + parentNode.symbol + " " +  printTree(parentNode.v1) + " " + printTree(parentNode.v2) + "]" 

def printPrettyTree(parentNode): 
    parseString = printTree(parentNode)
    stack = ['['] 
    tabs = 0 

    print(parseString[0] + parseString[1], end ='')
    for i in range(3, len(parseString)): 
        if parseString[i] == '[': 
            print('\n', end ='')
            if stack[-1] == '[': 
                tabs += 1
                print("   " * tabs, end ='')
            elif stack[-1] == ']': 
                print("   " * tabs, end ='')
            stack.append('[')

        if parseString[i] == ']':
            if stack[-1] == ']':
                tabs -= 1
                print("\n" + "   " * tabs, end ='')
            stack.append(']')

        print(parseString[i], end ='') 
    print("")


    
def main(): 
    grammarFileName = input("Enter the name of the file containing CNF grammar: ")
    grammarFile = open(grammarFileName, 'r')
    grammar = grammarFile.readlines()
    print("That's some fine lookin' grammar!")

    grammarList = []
    for line in grammar: 
        line = line.split()
        if len(line) == 4:
            grammarList.append([line[0], line[2], line[3]])
        else: 
            grammarList.append([line[0], line[2]])

    while True:  
        sentence = input("Enter a sentence to be parsed (or 'quit' to quit): ")     

        if sentence == 'quit': 
            print("Sad to see you go, farewell.")
            return 

        tokens = sentence.split()
        tokens = [re.sub(r'[^\w\s]', '', token.lower()) for token in tokens]
        

        chart = [[ [] for i in range(len(tokens) + 1)] for j in range(len(tokens))]

        for i, token in enumerate(tokens): 
            for rule in grammarList: 
                if rule[1] == token: 
                    chart[i][i + 1].append(Node(rule[0], token)) 
        
        for j in range(1, len(tokens) + 1): 
            for i in range(j - 2, -1, -1):
                for k in range(i + 1, j): 
                    rowlist = chart[i][k]
                    columnlist = chart[k][j]
                    if len(rowlist) > 0 and len(columnlist) > 0:
                        for rule in grammarList:
                            for rownode in rowlist: 
                                if rownode.symbol == rule[1]:
                                    for columnnode in columnlist: 
                                        if columnnode.symbol == rule[2]:
                                            chart[i][j].append(Node(rule[0], rownode, columnnode)) 
                            
        nodeList = []
        for value in chart[0][len(tokens)]: 
            if value.symbol == 'S': 
                nodeList.append(value)
        
        if len(nodeList) > 0: 
            print("\nVALID SENTENCE\n")
            valid = False 

            while valid == False: 
                inp = input("Would you like to see a textual parse tree? (y/n): ")
                if inp == 'y':
                    valid = True
                    print("----------------------------------------------------")

                    for i, node in enumerate(nodeList, 1): 
                        print("\nValid parse #" + str(i) + ":\n")
                        printPrettyTree(node)

                    print("\n\nNumber of valid parses: " + str(len(nodeList)) + '\n')
                    print("----------------------------------------------------")

                elif inp == 'n':
                    valid = True
                    print("----------------------------------------------------")

                    for i, node in enumerate(nodeList, 1): 
                        print("\nValid parse #" + str(i) + ":\n")
                        print(printTree(node))

                    print("\n\nNumber of valid parses: " + str(len(nodeList)) + '\n')
                    print("----------------------------------------------------")

                else: 
                    print("Not valid! Retry: ")
        else: 
            print("NO VALID PARSES")




if __name__ == "__main__": 
    main()
