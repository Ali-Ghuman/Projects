class Node:
    def __init__(self, value, link_node=None):
        self.value = value
        self.link_node = link_node
    
    def set_next_node(self, link_node):
        self.link_node = link_node
    
    def get_next_node(self):
        return self.link_node
  
    def get_value(self):
        return self.value

class Stack:
    def __init__(self, name):
        self.size = 0
        self.top_item = None
        self.limit = 1000
        self.name = name

    def push(self, value):
        if self.has_space():
            item = Node(value)
            item.set_next_node(self.top_item)
            self.top_item = item
            self.size += 1
        else:
            print("No more room!")

    def pop(self):
        if self.size > 0:
            item_to_remove = self.top_item
            self.top_item = item_to_remove.get_next_node()
            self.size -= 1
            return item_to_remove.get_value()
        print("This stack is totally empty.")

    def peek(self):
        if self.size > 0:
          return self.top_item.get_value()
        print("Nothing to see here!")

    def has_space(self):
        return self.limit > self.size

    def is_empty(self):
        return self.size == 0

    def get_size(self):
        return self.size

    def get_name(self):
        return self.name

    def print_items(self):
        pointer = self.top_item
        print_list = []
        while(pointer):
            print_list.append(pointer.get_value())
            pointer = pointer.get_next_node()
        print_list.reverse()
        print("{0} Stack: {1}".format(self.get_name(), print_list))


print("\nLet's play Towers of Hanoi!\n")

stacks = []

left_stack = Stack("Left")
right_stack = Stack("Right")
middle_stack = Stack("Middle")

stacks.append(left_stack) 
stacks.append(middle_stack)  
stacks.append(right_stack) 

num_disks = int(input("\nHow many disks do you want to play with? "))

if num_disks < 3: 
    while num_disks < 3: 
        num_disks = int(input("\nEnter a number greater than or equal to 3: "))

for i in range(num_disks, 0, -1):
    left_stack.push(i)

num_optimal_moves = 2**num_disks - 1

print(f"\nThe fastest you can solve this game is in {num_optimal_moves} moves\n")


def get_input():
    choices = [item.get_name()[0] for item in stacks] 
    while True: 
        for j in range(len(stacks)):
            name = stacks[j].get_name() 
            letter = choices[j]
            print(f"Enter {letter} for {name}")
        user_input = input(">") 
        if user_input in choices: 
            for k in range(len(stacks)): 
                if user_input == choices[k]: 
                    return stacks[k]
        else: 
            print("\nNot a valid option, retry\n")
                

num_user_moves = 0 

while right_stack.get_size() != num_disks: 
    print("\n\n\n...Current Stacks...") 
    for item in stacks: 
        item.print_items() 
    while True: 
        print("\nWhich stack do you want to move from?\n>")
        from_stack = get_input() 
        print("\nWhich stack do you want to move to?\n>")
        to_stack = get_input() 
        if from_stack.get_size() == 0: 
            print("\nInvalid move, try again.")
        elif to_stack.get_size() == 0 or from_stack.peek() < to_stack.peek(): 
            disk = from_stack.pop()
            to_stack.push(disk) 
            num_user_moves += 1
            break 

print(f"\n\nYou completed the game in {num_user_moves} and the optimal number \
of moves is {num_optimal_moves}")












