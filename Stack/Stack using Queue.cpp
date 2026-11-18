class MyStack {
public:
    queue<int> q;

    MyStack() {}

    void push(int x) {
        q.push(x);

        // yahan queue k elemnts ko reverse kia ha aik tarah se
        int size = q.size();
        for (int i = 0; i < size - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        int popped = q.front();
        q.pop();
        return popped;
    }

    int top() { return q.front(); }

    bool empty() { return q.empty(); }
};
