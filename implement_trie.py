# Trie in python fuark you LEET CODE for not accepting any of my C++ solutions.

class Node:
    def __init__(self):
        self.is_word = False
        self.children = {}
        self.letter = "" 
        

class Trie:

    root = None

    def __init__(self):
        self.root = Node()

    def insert(self, word: str) -> None:
        if(word == None):
            return

        if(self.root == None):
            self.root = Node()

        word.lower()
        current = self.root

        for c in word:
            if c not in current.children:
                child = Node()
                child.letter = c
                current.children[c] = child
            
            current = current.children[c]

        current.is_word = True
            

         

             
    def search(self, word: str) -> bool:
        if word == None:  
            return False
        if self.root == None: 
            return False 

        current = self.root
        for c in word: 
            # if the current's child doesn't exist, no word!
            if c not in current.children:
                return False
              
            # if none of that occured, just go to the next child
            current = current.children[c]

        return current.is_word
        

    def startsWith(self, prefix: str) -> bool:
        if prefix == None:  
            return False
        if self.root == None: 
            return False

        current = self.root
        for c in prefix:

            # if the current's child doesn't exist, no word!
            if c not in current.children:
                return False
            
            # if none of that occured, just go to the next child
            current = current.children[c]

        return True

    def print_trie(self):
        self.print_recursive(self.root, " ")

    def print_recursive(self, current, word_so_far):

        if current == None: 
            return 

        word_so_far = str(word_so_far) + str(current.letter)

        if current.is_word:
            print(word_so_far) 

        for child in current.children.values(): 
            self.print_recursive(child, word_so_far)
 

# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)

# ["Trie","insert","search","search","startsWith","insert","search"]
# [[],["apple"],["apple"],["app"],["app"],["app"],["app"]]

def main():
    t = Trie()
    t.insert("apple")
    t.insert("appetite")
    t.insert("derp")
    t.insert("barnacle")

    print(t.search("apple"))
    print(t.search("asdf"))
    print(t.search("apples")) 
    print(t.startsWith("app"))
    print(t.startsWith("azz"))
    
    
    #t.print_trie()

main()