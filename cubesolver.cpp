#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<int, int> pii;
const ll INFLL = 1e18 + 7;
const int INF = 1e9 + 7;
#define pb push_back

// cube is divided into strips that are used for making moves
int strips[6][3] = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6}, {1, 4, 7}, {2, 5, 8}};

// simple struct handling cube logic (making moves etc.)
struct cube
{
    vector<vector<int>> arr;
    cube()
    {
        arr.resize(6, vector<int>(9));
    }
    // solved cube
    void setup()
    {
        for (int i = 0; i < 6; ++i)
        {
            for (int j = 0; j < 9; ++j)
                arr[i][j] = i + 1;
        }
    }
    // swap 2 strips
    void swap_strips(int s1, int st1, int s2, int st2)
    {
        swap(arr[s1][strips[st1][0]], arr[s2][strips[st2][0]]);
        swap(arr[s1][strips[st1][1]], arr[s2][strips[st2][1]]);
        swap(arr[s1][strips[st1][2]], arr[s2][strips[st2][2]]);
    }
    // rotate side by 90 deg
    void rotate90(int side)
    {
        swap(arr[side][0], arr[side][6]);
        swap(arr[side][1], arr[side][3]);
        swap(arr[side][2], arr[side][6]);
        swap(arr[side][3], arr[side][7]);
        swap(arr[side][5], arr[side][7]);
        swap(arr[side][6], arr[side][8]);
    }
    // rotate side by 180 deg
    void rotate180(int side)
    {
        swap(arr[side][1], arr[side][7]);
        swap(arr[side][3], arr[side][5]);
        swap(arr[side][0], arr[side][8]);
        swap(arr[side][2], arr[side][6]);
    }
    // rotate side by 270 deg
    void rotate270(int side)
    {
        swap(arr[side][6], arr[side][8]);
        swap(arr[side][5], arr[side][7]);
        swap(arr[side][3], arr[side][7]);
        swap(arr[side][2], arr[side][6]);
        swap(arr[side][1], arr[side][3]);
        swap(arr[side][0], arr[side][6]);
    }
    // print cube state for debugging purposes
    void print(int side)
    {
        for (int a = 0; a < 3; ++a)
        {
            for (int b = 0; b < 3; ++b)
                cout << arr[side][a * 3 + b] << " ";
            cout << "\n";
        }
    }
    // make move of given type
    void make_move(string type)
    {
        if (type == "R")
        {
            rotate90(1);
            swap_strips(0, 5, 5, 5);
            swap_strips(2, 5, 5, 5);
            swap_strips(3, 5, 5, 5);
        }
        if (type == "R'")
        {
            rotate270(1);
            swap_strips(3, 5, 5, 5);
            swap_strips(2, 5, 5, 5);
            swap_strips(0, 5, 5, 5);
        }
        if (type == "R2")
        {
            rotate180(1);
            swap_strips(0, 5, 3, 5);
            swap_strips(2, 5, 5, 5);
        }
        if (type == "L")
        {
            rotate270(4);
            swap_strips(3, 3, 5, 3);
            swap_strips(2, 3, 5, 3);
            swap_strips(0, 3, 5, 3);
        }
        if (type == "L'")
        {
            rotate90(4);
            swap_strips(0, 3, 5, 3);
            swap_strips(2, 3, 5, 3);
            swap_strips(3, 3, 5, 3);
        }
        if (type == "L2")
        {
            rotate180(4);
            swap_strips(0, 3, 3, 3);
            swap_strips(2, 3, 5, 3);
        }
        if (type == "U")
        {
            rotate90(2);
            swap_strips(3, 0, 4, 0);
            swap_strips(1, 0, 4, 0);
            swap_strips(0, 0, 4, 0);
        }
        if (type == "U'")
        {
            rotate270(2);
            swap_strips(0, 0, 4, 0);
            swap_strips(1, 0, 4, 0);
            swap_strips(3, 0, 4, 0);
        }
        if (type == "U2")
        {
            rotate180(2);
            swap_strips(0, 0, 3, 0);
            swap_strips(1, 0, 4, 0);
        }
        if (type == "D")
        {
            rotate270(5);
            swap_strips(0, 2, 4, 2);
            swap_strips(1, 2, 4, 2);
            swap_strips(3, 2, 4, 2);
        }
        if (type == "D'")
        {
            rotate90(5);
            swap_strips(3, 2, 4, 2);
            swap_strips(1, 2, 4, 2);
            swap_strips(0, 2, 4, 2);
        }
        if (type == "D2")
        {
            rotate180(5);
            swap_strips(0, 2, 3, 2);
            swap_strips(1, 2, 4, 2);
        }
        if (type == "F")
        {
            rotate90(0);
            swap_strips(2, 2, 4, 3);
            swap_strips(1, 3, 4, 3);
            swap_strips(5, 2, 4, 3);
        }
        if (type == "F'")
        {
            rotate270(0);
            swap_strips(5, 2, 4, 3);
            swap_strips(1, 3, 4, 3);
            swap_strips(2, 2, 4, 3);
        }
        if (type == "F2")
        {
            rotate180(0);
            swap_strips(2, 2, 5, 2);
            swap_strips(1, 3, 4, 3);
        }
        if (type == "B")
        {
            rotate270(3);
            swap_strips(5, 0, 4, 5);
            swap_strips(1, 5, 4, 5);
            swap_strips(2, 0, 4, 5);
        }
        if (type == "B'")
        {
            rotate90(3);
            swap_strips(2, 0, 4, 5);
            swap_strips(1, 5, 4, 5);
            swap_strips(5, 0, 4, 5);
        }
        if (type == "B2")
        {
            rotate180(3);
            swap_strips(2, 0, 5, 0);
            swap_strips(1, 5, 4, 5);
        }
    }
    // convert cube to pair representation
    pair<ull, ull> get_shortcode()
    {
        ull a = 0, b = 0;
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                if (j == 4)
                    continue;
                a *= 6;
                a += arr[i][j];
            }
        }
        for (int i = 3; i < 6; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                if (j == 4)
                    continue;
                b *= 6;
                b += arr[i][j];
            }
        }
        return {a, b};
    }
    // convert cube to bitset representation
    bitset<165> get_code()
    {
        bitset<165> res;
        int curr_bit = 0;
        for (int i = 0; i < 6; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                res[curr_bit++] = arr[i][j] & 1;
                res[curr_bit++] = arr[i][j] & 2;
                res[curr_bit++] = arr[i][j] & 4;
            }
        }
        return res;
    }
};

// function converting cube bitcode to array
vector<vector<int>> convert_to_cube(bitset<165> &code)
{
    int curr_bit = 0;
    vector<vector<int>> res(6, vector<int>(9));
    for (int i = 0; i < 6; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            res[i][j] |= (code[curr_bit++]);
            res[i][j] |= (code[curr_bit++] << 1);
            res[i][j] |= (code[curr_bit++] << 2);
        }
    }
    return res;
}

// list of possible moves
vector<string> moves = {"R", "R'", "R2", "L", "L'", "L2", "U", "U'", "U2",
                        "D", "D'", "D2", "F", "F'", "F2", "B", "B'", "B2"};

// struct holding the solution
struct solution
{
    int positions_checked;
    int length;
    vector<string> moves;
    void print_solution()
    {
        cout << "\n/*************************************/\n\n";
        cout << "Found solution in " << length << " moves\n";
        cout << "Checked " << positions_checked << " positions in the proccess\n";
        for (string &move : moves)
            cout << move << " ";
        cout << "\n\n/*************************************/\n";
    }
};

// hash function for pairs
struct pair_hash
{
    size_t operator()(const pair<ull, ull> &p) const
    {
        return (p.first ^ p.second);
    }
};

// function to find the solution for given cube state
solution solve(cube init)
{
    // setting codes for solved state for faster comparison
    cube solved_state;
    solved_state.setup();
    bitset<165> dest_code;
    pair<ull, ull> dest;
    dest_code = solved_state.get_code();
    dest = solved_state.get_shortcode();
    cube start_pos = init;
    // queues for 2 source BFS
    vector<bitset<165>> Q = {start_pos.get_code()}, Q2 = {dest_code};
    Q[0][162] = 1;
    Q2[0][162] = 1;
    Q[0][163] = 1;
    Q2[0][163] = 1;
    Q[0][164] = 1;
    Q2[0][164] = 1;
    // setting hash maps for visited states
    unordered_map<pair<ull, ull>, char, pair_hash> visited, visited2;
    visited.insert({start_pos.get_shortcode(), 18});
    visited2.insert({dest, 18});
    // other decarations
    cube l_pos, r_pos;
    int middle_move = 0;
    int cnt = 0;
    // BFS from 2 sources (initial state and solved state)
    while (1)
    {
        vector<bitset<165>> tmp;
        cube curr;
        for (bitset<165> &b : Q)
        {
            int last_move_type = (int)b[162] + ((int)b[163] << 1) + ((int)b[164] << 2);
            curr.arr = convert_to_cube(b);
            for (int j = 0; j < 18; ++j)
            {
                if (j / 3 == last_move_type)
                    continue;
                curr.make_move(moves[j]);
                pair<ull, ull> shortcode = curr.get_shortcode();
                if (!visited.count(shortcode))
                {
                    if (shortcode == dest || visited2.count(shortcode))
                    {
                        r_pos = curr;
                        if (j % 3 == 0)
                            curr.make_move(moves[j + 1]);
                        else if (j % 3 == 1)
                            curr.make_move(moves[j - 1]);
                        else
                            curr.make_move(moves[j]);
                        l_pos = curr;
                        middle_move = j;
                        goto printpath;
                    }
                    visited.insert({shortcode, j});
                    ++cnt;
                    bitset<165> curr_code = curr.get_code();
                    int move_type = j / 3;
                    curr_code[162] = move_type & 1;
                    curr_code[163] = move_type & 2;
                    curr_code[164] = move_type & 4;
                    tmp.pb(curr_code);
                }
                if (j % 3 == 0)
                    curr.make_move(moves[j + 1]);
                else if (j % 3 == 1)
                    curr.make_move(moves[j - 1]);
                else
                    curr.make_move(moves[j]);
            }
        }
        Q = tmp;
        tmp.clear();
        for (bitset<165> &b : Q2)
        {
            int last_move_type = (int)b[162] + ((int)b[163] << 1) + ((int)b[164] << 2);
            curr.arr = convert_to_cube(b);
            for (int j = 0; j < 18; ++j)
            {
                if (j / 3 == last_move_type)
                    continue;
                curr.make_move(moves[j]);
                pair<ull, ull> shortcode = curr.get_shortcode();
                if (!visited2.count(shortcode))
                {
                    if (visited.count(shortcode))
                    {
                        l_pos = curr;
                        if (j % 3 == 0)
                            curr.make_move(moves[j + 1]);
                        else if (j % 3 == 1)
                            curr.make_move(moves[j - 1]);
                        else
                            curr.make_move(moves[j]);
                        r_pos = curr;
                        if (j % 3 == 0)
                            ++j;
                        else if (j % 3 == 1)
                            --j;
                        middle_move = j;
                        goto printpath;
                    }
                    visited2.insert({shortcode, j});
                    ++cnt;
                    bitset<165> curr_code = curr.get_code();
                    int move_type = j / 3;
                    curr_code[162] = move_type & 1;
                    curr_code[163] = move_type & 2;
                    curr_code[164] = move_type & 4;
                    tmp.pb(curr_code);
                }
                if (j % 3 == 0)
                    curr.make_move(moves[j + 1]);
                else if (j % 3 == 1)
                    curr.make_move(moves[j - 1]);
                else
                    curr.make_move(moves[j]);
            }
        }
        Q2 = tmp;
    }
    // restoring moves of the found solution
    printpath:
    vector<int> lpath, rpath;
    while (visited[l_pos.get_shortcode()] != 18)
    {
        int move = visited[l_pos.get_shortcode()];
        lpath.pb(move);
        if (move % 3 == 0)
            ++move;
        else if (move % 3 == 1)
            --move;
        l_pos.make_move(moves[move]);
    }
    reverse(lpath.begin(), lpath.end());
    while (visited2[r_pos.get_shortcode()] != 18)
    {
        int move = visited2[r_pos.get_shortcode()];
        if (move % 3 == 0)
            ++move;
        else if (move % 3 == 1)
            --move;
        rpath.pb(move);
        r_pos.make_move(moves[move]);
    }
    vector<int> res;
    res = lpath;
    res.pb(middle_move);
    for (int &v : rpath)
        res.pb(v);
    solution ans;
    ans.positions_checked = cnt;
    ans.length = res.size();
    for (int &v : res)
        ans.moves.pb(moves[v]);
    return ans;
}

// function to convert list of moves to cube and find solution using "solve" function
void solve_cube(vector<string> &_moves)
{
    cube start_pos;
    start_pos.setup();
    for (string &s : _moves)
        start_pos.make_move(s);
    solution sol = solve(start_pos);
    sol.print_solution();
}

int main()
{
    ios_base::sync_with_stdio(0);
    //~ vector<string> example={"D'","U'","D","L","L","D'","R'","R'","F","R","B2","L2","D"};
    //~ solve_cube(example);
    vector<string> moves_to_make;
    while (1)
    {
        string move;
        cin >> move;
        if (move == "0")
            break;
        moves_to_make.pb(move);
    }
    solve_cube(moves_to_make);
}
