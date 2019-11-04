// In an exam room, there are N seats in a single row, numbered 0, 1, 2, ...,
// N-1.
//
// When a student enters the room, they must sit in the seat that maximizes the
// distance to the closest person.  If there are multiple such seats, they sit
// in the seat with the lowest number.  (Also, if no one is in the room, then
// the student sits at seat number 0.)
//
// Return a class ExamRoom(int N) that exposes two functions: ExamRoom.seat()
// returning an int representing what seat the student sat in, and
// ExamRoom.leave(int p) representing that the student in seat number p now
// leaves the room.  It is guaranteed that any calls to ExamRoom.leave(p) have a
// student sitting in seat p.
//
//
//
// Example 1:
//
// Input: ["ExamRoom","seat","seat","seat","seat","leave","seat"],
// [[10],[],[],[],[],[4],[]] Output: [null,0,9,4,2,null,5] Explanation:
// ExamRoom(10) -> null
// seat() -> 0, no one is in the room, then the student sits at seat number 0.
// seat() -> 9, the student sits at the last seat number 9.
// seat() -> 4, the student sits at the last seat number 4.
// seat() -> 2, the student sits at the last seat number 2.
// leave(4) -> null
// seat() -> 5, the student​​​​​​​ sits at the last seat number 5.
// ​​​​​​​
//
// Note:
//
// 1 <= N <= 10^9
// ExamRoom.seat() and ExamRoom.leave() will be called at most 10^4 times across
// all test cases. Calls to ExamRoom.leave(p) are guaranteed to have a student
// currently sitting in seat number p.

class ExamRoom {
public:
    int N;
    vector<int> seats;
    ExamRoom(int N) { this->N = N; }

    int seat() {
        int sit = 0;
        int gap = 0;
        int i = 0, j = 0;

        for (auto s : seats) {
            if (i == 0 && s - i > gap) {
                gap = s - i;
                sit = i;
            } else {
                if ((s - i + 1) / 2 > gap) {
                    gap = (s - i + 1) / 2;
                    sit = i + gap - 1;
                }
            }
            i = s + 1;
        }

        if (N - i > gap && i != 0) {
            gap = N - i;
            sit = N - 1;
        }

        int pos = 0;
        for (; pos < seats.size(); ++pos) {
            if (seats[pos] > sit) {
                break;
            }
        }
        seats.insert(seats.begin() + pos, sit);

        return sit;
    }

    void leave(int p) {
        for (int i = 0; i < seats.size(); ++i) {
            if (seats[i] == p) {
                seats.erase(seats.begin() + i);
                break;
            }
        }
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom obj = new ExamRoom(N);
 * int param_1 = obj.seat();
 * obj.leave(p);
 */
