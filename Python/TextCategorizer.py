from nltk.stem import PorterStemmer
from nltk.tokenize import word_tokenize
from collections import Counter
from math import log

#Input and output file names are taken
trainInput = input("Enter the path of the training file: ")
testInput = input("Enter the path of the test file: ")

k = 0.05  #an additive smoothing constant

def trainBayes(trainInput, testInput):
    trainF = open(trainInput, 'r')     #read in the input path and split on a line by line basis
    trainF = trainF.readlines() 

    wordFreqCat = {} #count of word given category 
    wordFreq = {} #number of words in each category
    catFreq = {}  #each category and how many times they appear 
    numDocs = len(trainF)

    stemmer = PorterStemmer()    #set up stemmer

    for line in trainF: 
        lineSplit = line.split()  #break up the line into path and category
        category = lineSplit[1]

        if category in catFreq:  #get the number of times a category appears in the training docs
            catFreq[category] += 1 
        else: 
            catFreq[category] = 1

        document =  open(lineSplit[0], 'r')
        trainTokenized = word_tokenize(document.read())  #tokenize and stem the words 
        trainTokenized = [stemmer.stem(word) for word in trainTokenized]

        if category in wordFreq:   #get the amount of words that appear in each category
            wordFreq[category] += len(trainTokenized)
        else: 
            wordFreq[category] = len(trainTokenized)

        for token in trainTokenized:   #get the times a word appears with a given category in the training docs
            if (category, token) in wordFreqCat: 
                wordFreqCat[(category, token)] += 1
            else:
                wordFreqCat[(category, token)] = 1
        
        document.close()

    categoryList = list(catFreq.keys())  #get a list of all the categories
    priorProb = {category : log(catFreq[category]/numDocs) for category in categoryList} #set up a dict of category : priorProbability

    testF = open(testInput, 'r')        
    testF = testF.readlines()  #read in the test file list and split on line by line basis
    outputList = []  #set up the output decisions in a labeled list of path with category 

    for line in testF: 
        tdocument =  open(line[:-1], 'r')
        testTokenized = word_tokenize(tdocument.read())   #tokenize and stem test document
        testTokenized = [stemmer.stem(word) for word in testTokenized]
        testFreq = dict(Counter(testTokenized)) #get word to frequency counts in the test document
        vocabSize = len(testFreq)

        logProbsCat = {category : 0 for category in categoryList} #zero the loglikelihoods 

        for category in categoryList: 
            totalProb = 0 #Zero the total probability for the given category

            for word, frequency in testFreq.items():                     
                if (category, word) in wordFreqCat:  #if the token in the testing is in the training, add the appropriate probability 
                    countCat = wordFreqCat[(category, word)] + k  
                else: 
                    countCat = k   #if the word doesn't appear with the given category, only add the smoothing constant
                
                totalProb += frequency*log(countCat/(wordFreq[category] + k*vocabSize)) #get the total loglikelihood 
            logProbsCat[category] = totalProb + priorProb[category] #add each priorProb to the total loglikelihood
   
        outputList.append(line[:-1] + ' ' + max(logProbsCat, key = lambda k: logProbsCat[k]) + '\n') #append the decision to the output list in path category format
        tdocument.close() 

    testOutput = input("Enter the name of the output file: ")

    with open(testOutput, 'w') as testOutput:  #open output file and read in the outputList into it line by line
        for line in outputList: 
            testOutput.write(line)


trainBayes(trainInput, testInput)


