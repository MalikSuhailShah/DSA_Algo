#include <iostream>
using namespace std;

// using 4 parameter      (INDEXING IS FROM 0 TO N)

int maze(int cr, int cc, int er, int ec)
{
    // cc= current column, cr=current columnb, ec=ending columnl,er=ending row;
    if (cc > ec || cr > er)
        return 0;
    if (cc == ec && cr == er)
        return 1;

    int rightways = maze(cr, cc + 1, er, ec);
    int downways = maze(cr + 1, cc, er, ec);
    return rightways + downways;
}

void printpath(int cr, int cc, int er, int ec, string s)
{
    if (cr > er || cc > ec) return;
    if(cr==er && cc==ec) {
        cout<<s<<endl;
        return ;
    }

    printpath(cr,cc+1,er,ec,s+'R'); //Right move
    printpath(cr+1,cc,er,ec,s+'D'); // down move;
}

// using 2 parameter      (INDEXING IS FROM 0 TO N)

int maze2(int rows, int cols)
{
    if (rows<0 || cols < 0)
        return 0;

    if (rows == 0 && cols == 0)
        return 1;

    int rightways = maze2(rows, cols - 1);
    int downways = maze2(rows - 1, cols);

    return rightways + downways;
}

void printpath2(int rows, int cols, string s)
{
    if (cols < 0 || rows < 0)
        return;

    if (cols == 0 && rows == 0)
    {
        cout << s << endl;
        return;
    }

    printpath2(rows, cols - 1, s + 'R'); // right move;

    printpath2(rows - 1, cols, s + 'D'); // down move;
}
int main()
{

    cout<<maze(0,0,2,2)<<endl;
    printpath(0,0,2,2,"");

    cout<<maze2(2,2)<<endl;
    printpath2(2,2,"");

}