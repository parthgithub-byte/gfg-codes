class twoStacks {
  public:


    vector<int>arr;
    int first, second;
    
    twoStacks() {
        arr.resize(100);
        first = -1;
        second = 100;
    }
        
    // Function to push an integer into the stack1.
    void push1(int x) {
        // code here
        first++;
        arr[first] = x;
    }

    // Function to push an integer into the stack2.
    void push2(int x) {
        second--;
        arr[second] = x;
        // code here
    }

    // Function to remove an element from top of the stack1.
        
    int pop1() {
        // code here
        if(first<0) return -1;
        return arr[first--];
    }

        
    // Function to remove an element from top of the stack2.
    int pop2() {
        // code here
        if (second>99) return -1;
        return arr[second++];
    }
};