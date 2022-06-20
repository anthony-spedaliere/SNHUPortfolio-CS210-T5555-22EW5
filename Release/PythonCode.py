import re
import string



#Function to count the daily purchases of each item at the Corner Grocer

#@params string fileName takes in a filename path

#return int
    

def countDailyPurchases(fileName):

    with open(fileName, "r") as file1:
        mylist = file1.read().split("\n")
        myset = set(mylist)
        

    counter = 0 

    for item in myset:
        counter = mylist.count(item)
        print(item + " " + str(counter))

    return 1




#Function to search list of purchases and return a single result showing the frequency it was purchased 

#@params string item containing the users query

#@return int representing frequency item was purchased

def searchPurchases(item):

    with open("inputFile.txt", "r") as file1:
        mylist = file1.read().split("\n")
        myset = set(mylist)
        file1.close()

    counter = 0 
    
    item = item.lower()    
    item = item.capitalize()
        
    if item in mylist:
        counter = mylist.count(item)
    
    return counter
    



#Function to create a new file and store the set of purchased items and frequencies

#@params string fileName takes in a filename path that has the original list of purchased items

#@return int 
    
def createFile(fileName):

    with open(fileName, "r") as file1:
        mylist = file1.read().split("\n")
        myset = set(mylist)

    counter = 0 
   
    with open("frequency.dat", 'w') as file2:
        for item in myset:
            counter = mylist.count(item)
            file2.write(item + " " + str(counter) + "\n")
    
    return 1