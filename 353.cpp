class SnakeGame {
public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1],
       the second is at [1,0]. */
    deque<pair<int, int>> dq;
    set<pair<int, int>> s;
    int pos;
    vector<pair<int, int>> food;
    int width;
    int height;
    SnakeGame(int width, int height, vector<pair<int, int>> food) {
        this->pos = 0;
        this->food = food;
        this->width = width;
        this->height = height;
        dq.push_back({0, 0});
    }

    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down
        @return The game's score after the move. Return -1 if game over.
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        pair<int, int> head = dq.front();
        pair<int, int> tail = dq.back();
        dq.pop_back();
        if (s.count(tail)) {
            s.erase(tail);
        }

        for (auto c : direction) {
            switch (c) {
            case 'U':
                head.first--;
                break;
            case 'D':
                head.first++;
                break;
            case 'L':
                head.second--;
                break;
            case 'R':
                head.second++;
                break;
            }
        }

        if (head.first < 0 || head.first >= height || head.second < 0
            || head.second >= width || s.count(head)) {
            return -1;
        }

        dq.push_front(head);
        s.insert(head);
        if (pos < food.size() && food[pos] == head) {
            pos++;
            dq.push_back(tail);
            s.insert(tail);
        }

        return s.size() - 1;
    }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame obj = new SnakeGame(width, height, food);
 * int param_1 = obj.move(direction);
 */
