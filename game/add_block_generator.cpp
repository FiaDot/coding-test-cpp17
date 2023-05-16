#include <iostream>
#include <algorithm>
#include <random>
#include <vector>
#include <stack>
#include <iomanip>

// n by m 배열에 1~9 수만큼 랜덤하게 배치
// 0인 칸도 있음 ㅋㅋ

using namespace std;

int dir[4][2] = {
        {0,1}, {0, -1}, {-1, 0}, {1, 0}
};

const int sx = 5;
const int sy = 5;


// 배열을 초기화합니다.
int board[sy][sx] = {0};

int nums[sy][sx] = {0};

bool visited[sy][sx];

bool CanBlock(int x, int y)
{
    if ( x < 0 || x >= sx )
        return false;

    if ( y < 0 || y >= sy )
        return false;

//    return board[y][x] == 0;

    if ( board[y][x] != 0 )
        return false;

    return !visited[y][x];
}

void SetVisited(int x, int y)
{
    if ( x < 0 || x >= sx )
        return;

    if ( y < 0 || y >= sy )
        return;

    visited[y][x] = true;
}


void ClearIdx(int idx) {
    for (int i = 0; i < sy; i++) {
        for (int j = 0; j < sx; j++) {
            if ( board[i][j] == idx )
            {
                board[i][j] = 0;
                visited[i][j] = false;
                nums[i][j] = 0;
            }
        }
    }
}

int arDir[4] = {0,1,2,3};
const int targetNumber = 17; // 9,22,15,17

bool verify(int targetNumber, vector<int> numbers) {
    int n = numbers.size();

    // 1부터 2^n까지의 모든 2진수를 반복합니다.
    for (int i = 1; i < (1 << n); i++) {
        int sum = 0;

        // i의 비트가 1인 모든 숫자를 부분 집합에 추가합니다.
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                sum += numbers[j];
            }
        }

        if ( targetNumber == sum )
            return true;
    }

    return false;
}

int main() {
    const int maxNumber = 9;
    std::random_device rd;
    // std::mt19937 gen(rd());
    std::mt19937 gen(9);// 3이 정상, 4가 실패
    std::uniform_int_distribution<int> dis(1, maxNumber);
    //std::uniform_int_distribution<int> rand4(0, 3);

    vector<int> numbers;

    // 배열 초기화
    for (int i = 0; i < sy; i++) {
        for (int j = 0; j < sx; j++) {
            visited[i][j] = false;
        }
    }


    int label = 1;

    for (int i = 0; i < sy; i++){
        for (int j = 0; j < sx; j++) {
            if (board[i][j] != 0)
                continue;

            int number = dis(gen);
            int count = number-1;

            // DFS
            stack<pair<int, int>> s;
            int x = j;
            int y = i;
            s.push({x,y});

            SetVisited(x, y);
            board[y][x] = label;
            nums[y][x] = number;

            // 4방향 랜덤하게 접근
            std::shuffle(arDir, arDir + 4, gen);

            while( !s.empty() && count > 0) {
                pair<int,int> p = s.top();
                x = p.first;
                y = p.second;
                s.pop();

                for(int n=0;n<4;n++)
                {
                    int selDir = arDir[n];

                    int dx = x + dir[selDir][0];
                    int dy = y + dir[selDir][1];

                    if (!CanBlock(dx, dy)) {
                        SetVisited(dx, dy);
                        continue;
                    }

                    board[dy][dx] = label;
                    nums[dy][dx] = number;
                    SetVisited(dx, dy);
                    count--;

                    if ( count <= 0 )
                        break;

                    s.push({x, y});
                    s.push({dx, dy});
                }
            }

            if ( 0 < count )
            {
                cout << "err=" << label << endl;
                ClearIdx(label);
            }
            else
            {
                numbers.push_back(number);
            }

            label++;
        }
    }

    int total=0;
    for(int k: numbers )
    {
        cout << k << " ";
        total += k;
    }
    cout << endl << "total=" << total << endl;

    if ( verify(targetNumber, numbers) )
        cout << targetNumber << " success verified" << endl;
    else
        cout << targetNumber << " failed verified" << endl;


    cout << "label" << endl;
    for (int i = 0; i < sy; i++) {
        for (int j = 0; j < sx; j++) {
            cout << setw(2) << board[i][j] << " ";
        }
        cout << endl;
    }

    cout << "nums" << endl;
    for (int i = 0; i < sy; i++) {
        for (int j = 0; j < sx; j++) {
            cout << setw(2) << nums[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
