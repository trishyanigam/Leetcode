class Robot {
public:
    int width, height, perimeter;
    int x = 0, y = 0;
    int dir = 0; // 0=East, 1=North, 2=West, 3=South

    Robot(int width, int height) {
        this->width = width;
        this->height = height;
        perimeter = 2 * (width + height - 2);
    }

    void step(int num) {
        num %= perimeter;

        while (num > 0) {
            if (dir == 0) { // East
                int move = min(num, width - 1 - x);
                x += move;
                num -= move;
                if (num > 0) dir = 1;
            }
            else if (dir == 1) { // North
                int move = min(num, height - 1 - y);
                y += move;
                num -= move;
                if (num > 0) dir = 2;
            }
            else if (dir == 2) { // West
                int move = min(num, x);
                x -= move;
                num -= move;
                if (num > 0) dir = 3;
            }
            else { // South
                int move = min(num, y);
                y -= move;
                num -= move;
                if (num > 0) dir = 0;
            }
        }

        // Special case: when we return to (0,0)
        if (x == 0 && y == 0 && num == 0) {
            dir = 3; // South
        }
    }

    vector<int> getPos() {
        return {x, y};
    }

    string getDir() {
        if (dir == 0) return "East";
        if (dir == 1) return "North";
        if (dir == 2) return "West";
        return "South";
    }
};