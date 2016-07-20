#include <iostream>

using namespace std;

struct chessElements
{
    int pieceatxy;
    char team;
}chess[8][8];

char str[9][9]={{' ','1','2','3','4','5','6','7','8'},{'1','R','N','B','K','Q','B','N','R'},{'2','P','P','P','P','P','P','P','P'},{'3','0','0','0','0','0','0','0','0'},{'4','0','0','0','0','0','0','0','0'},{'5','0','0','0','0','0','0','0','0'},{'6','0','0','0','0','0','0','0','0'},{'7','p','p','p','p','p','p','p','p'},{'8','r','n','b','k','q','b','n','r'}};

const int king=4;
const int queen=5;
const int knight=2;
const int bishop=3;
const int rook=1;
const int pawn=6;

char ch='n';

class chessMethods
{
public:
    int i;
    char reply;
    void initializeboard()
    {
        int count=1;
        for(i=0;i<8;i++)
        {
            chess[0][i].pieceatxy=count;
            chess[7][i].pieceatxy=count;
            chess[0][i].team='b';
            chess[7][i].team='w';
            chess[1][i].team='b';
            chess[6][i].team='w';
            chess[1][i].pieceatxy=6;
            chess[6][i].pieceatxy=6;

            if(i<=3)
                count++;
            else if(i==4)
                count-=2;
            else
                count--;
        }
        for(int i=2;i<6;i++)
            for(int j=0;j<8;j++)
            {
                chess[i][j].pieceatxy=0;
                chess[i][j].team='n';
            }
    }

    int check(int sr,int sc,int dr,int dc,char ch)
    {
        if(chess[sr][sc].pieceatxy!=0 && chess[sr][sc].team==ch)
        {
            if(chess[dr][dc].pieceatxy==0 || chess[dr][dc].team==((ch=='b')?'w':'b'))
                return 1;
            else
                return 0;
        }
        else
            return 0;
    }

    int forDiagonally(int &sr,int &sc,int &dr,int &dc)
    {
                if(sr>dr && sc<dc)
                {
                    for(i=1;i<sr-dr;i++)
                    {
                        if(chess[sr-i][sc+i].pieceatxy!=0)
                        {
                            if(chess[sr-i][sc+i].team==ch)
                            {
                                cout<<"Own Player in path";
                                cout<<"Cant attack";
                                return 0;
                            }
                            else
                            {
                                label3:
                                    cout<<"Do u want to take over the piece in path(y/n):";
                                        cin>>reply;
                                        if(reply=='y' || reply=='Y')
                                        {
                                            dr=dr+(dr-sr-i);
                                            dc=dc-(dr-sr-i);
                                            break;
                                        }
                                        else if(reply=='n' || reply=='N')
                                        {
                                            cout<<"Wrong Path";
                                            return 0;
                                        }
                                        else
                                        {
                                            cout<<"\nGive answer appropriately";
                                            goto label3;

                                        }

                            }
                        }
                    }
                    return 1;
                }


                else if(sr<dr && sc>dc)
                {
                    for(i=1;i<dr-sr;i++)
                    {
                        if(chess[sr+i][sc-i].pieceatxy!=0)
                        {
                            if(chess[sr+i][sc-i].team==ch)
                            {
                                cout<<"Own Player in path";
                                cout<<"Cant attack";
                                return 0;
                            }
                            else
                            {
                                label4:
                                    cout<<"Do u want to take over the piece in path(y/n):";
                                        cin>>reply;
                                        if(reply=='y' || reply=='Y')
                                        {
                                            dr=dr-(dr-sr-i);
                                            dc=dc+(dr-sr-i);
                                            break;
                                        }
                                        else if(reply=='n' || reply=='N')
                                        {
                                            cout<<"Wrong Path";
                                            return 0;
                                        }
                                        else
                                        {
                                            cout<<"\nGive answer appropriately";
                                            goto label4;

                                        }

                            }
                        }
                    }
                    return 1;
                }

                else if(sr<dr && sc<dc)
                {
                    for(i=1;i<dr-sr;i++)
                    {
                        if(chess[sr+i][sc+i].pieceatxy!=0)
                        {
                            if(chess[sr+i][sc+i].team==ch)
                            {
                                cout<<"Own Player in path";
                                cout<<"Cant attack";
                                return 0;
                            }
                            else
                            {
                                label5:
                                    cout<<"Do u want to take over the piece in path(y/n):";
                                        cin>>reply;
                                        if(reply=='y' || reply=='Y')
                                        {
                                            dr=dr-(dr-sr-i);
                                            dc=dc-(dr-sr-i);
                                            break;
                                        }
                                        else if(reply=='n' || reply=='N')
                                        {
                                            cout<<"Wrong Path";
                                            return 0;
                                        }
                                        else
                                        {
                                            cout<<"\nGive answer appropriately";
                                            goto label5;

                                        }

                            }
                        }
                    }
                    return 1;
                }

                else
                {
                    for(i=1;i<sr-dr;i++)
                    {
                        if(chess[sr-i][sc-i].pieceatxy!=0)
                        {
                            if(chess[sr-i][sc-i].team==ch)
                            {
                                cout<<"Own Player in path";
                                cout<<"Cant attack";
                                return 0;
                            }
                            else
                            {
                                 label6:
                                    cout<<"Do u want to take over the piece in path(y/n):";
                                        cin>>reply;
                                        if(reply=='y' || reply=='Y')
                                        {
                                            dr=dr+(sr-dr-i);
                                            dc=dc+(sr-dr-i);
                                            break;
                                        }
                                        else if(reply=='n' || reply=='N')
                                        {
                                            cout<<"Wrong Path";
                                            return 0;
                                        }
                                        else
                                        {
                                            cout<<"\nGive answer appropriately\n";
                                            goto label6;

                                        }
                            }
                        }
                    }
                    return 1;
                }
    }
   /* int tedha(int &sr,int &sc,int &dr,int &dc)
    {
        for(int i=1;i<8;i++)
        {
            if((dr==sr+i && dc==sc+i) || (dr==sr+i && dc==sc-i) || (dr==sr-i && dc==sc+i) || (dr==sr-i && dc==sc-i))
            {
                if(forDiagonally(sr,sc,dr,dc))
                    return 1;
                else 
                    return 0;
            }
            else
                return 0;

        }
    }*/

    int forRow(int &sr,int &sc,int &dr,int &dc)
    {
                    if(dc<=sc)
                    {
                        for(i=sc-1;i>=dc+1;i--)
                        {
                            if(chess[sr][i].pieceatxy!=0)
                            {
                                if(chess[sr][i].team==ch)               //if path contains the attacking team piece
                                {
                                    cout<<"\nOwn Player in path\n";
                                    cout<<"Can't attack\n";
                                    return 0;
                                }

                                else
                                {
                                    label7:                               //if path contains opponents piece
                                        cout<<"Do u want to take over the piece in path(y/n):";
                                        cin>>reply;                         //asking if want to take over the piece in path
                                        if(reply=='y' || reply=='Y')
                                        {
                                            dc=i;
                                            break;
                                        }
                                        else if(reply=='n' || reply=='N')
                                        {
                                            cout<<"Wrong Path";
                                            return 0;
                                        }
                                        else
                                        {
                                            cout<<"\nGive answer appropriately\n";
                                            goto label7;
                                        }
                                }
                            }
                        }

                    }
                    else
                    {
                        for(i=sc+1;i<=dc-1;i++)
                        {
                            if(chess[sr][i].pieceatxy!=0)
                            {
                                if(chess[sr][i].team==ch)
                                {
                                    cout<<"\nOwn Player in path\n";
                                    cout<<"Can't attack\n";
                                    return 0;
                                }
                                else
                                {
                                    label8:
                                        cout<<"Do u want to take over the piece in path(y/n):";
                                        cin>>reply;
                                        if(reply=='y' || reply=='Y')
                                        {
                                            dc=i;
                                            break;
                                        }
                                        else if(reply=='n' || reply=='N')
                                        {
                                            cout<<"Wrong Path";
                                            return 0;
                                        }
                                        else
                                        {
                                            cout<<"\nGive answer appropriately";
                                            goto label8;
                                        }
                                }
                            }
                        }
                    }
                    return 1;
    }


    int forColumn(int &sr,int &sc,int &dr,int &dc)
    {
                    if(sr<=dr)
                    {
                        for(i=sr+1;i<=dr-1;i++)
                        {
                            if(chess[i][sc].pieceatxy!=0)
                            {
                                if(chess[i][sc].team==ch)
                                {
                                    cout<<"Own Player in path";
                                    cout<<"cant attack";
                                    return 0;
                                }
                                else
                                {
                                    label9:
                                        cout<<"Do u want to take over the piece in path(y/n):";
                                        cin>>reply;
                                        if(reply=='y' || reply=='Y')
                                        {
                                            dr=i;
                                            break;
                                        }
                                        else if(reply=='n' || reply=='N')
                                        {
                                            cout<<"Wrong Path";
                                            return 0;
                                        }
                                        else
                                        {
                                            cout<<"\nGive answer appropriately";
                                            goto label9;
                                        }
                                }
                            }
                        }
                    }

                    else                                     //wrongly written this else part.modifications required
                    {
                        for(i=sr-1;i>=dr+1;i--)
                        {
                            if(chess[i][sc].pieceatxy!=0)
                            {
                                if(chess[i][sc].team==ch)
                                {
                                    cout<<"\nOwn Player in path\n";
                                    cout<<"Can't attack\n";
                                    return 0;
                                }
                                else
                                {
                                    label10:
                                        cout<<"Do u want to take over the piece in path(y/n):";
                                        cin>>reply;
                                        if(reply=='y' || reply=='Y')
                                        {
                                            dc=i;
                                            break;
                                        }
                                        else if(reply=='n' || reply=='N')
                                        {
                                            cout<<"Wrong Path";
                                            return 0;
                                        }
                                        else
                                        {
                                            cout<<"\nGive answer appropriately";
                                            goto label10;
                                        }
                                }
                            }
                        }
                    }
                    return 1;
    }

    int isMoveValid(int &sr,int &sc,int &dr,int &dc)                       //checks whether move is valid
    {
        switch(chess[sr][sc].pieceatxy)
        {
            case 4:                                                     //for king
                if(((dr==sr+1 || dr==sr-1) && (dc==sc+1 || dc==sc-1)) || ((dr==sr+1 || dr==sr-1) && (dc==sc)) || ((dc==sc+1 || dc==sc-1) && (dr==sr)))
                    return 1;
                else
                    return 0;
            case 5:                                                        //for queen
                if(sr==dr)                                                 //if queen moves in a horizontal row
                {
                    if(forRow(sr,sc,dr,dc))
                        return 1;
                    else 
                        return 0;
                    
                }

                else if(sc==dc)                                     //if moves in a vertical column
                {
                    if(forColumn(sr,sc,dr,dc))
                        return 1;
                    else 
                        return 0;
 
                }

                else if(forDiagonally(sr,sc,dr,dc))
                    return 1;

                else 
                    return 0;

            case 3:
                if(forDiagonally(sr,sc,dr,dc))
                    return 1;
                else
                    return 0;

            case 2:
                if((dr==sr+2 && dc==sc+1) || (dr==sr+2 && dc==sc-1) || (dr==sr-2 && dc==sc+1) || (dr==sr-2 && dc==sc-1)|| (dc==sc+2 && dr==sr+1) || (dc==sc+2 && dr==sr-1)|| (dc==sc-2 && dr==sr+1) || (dc==sc-2 && dr==sr-1))
                    return 1;
                else
                    return 0;

            case 6:                                                                   //for pawn
                if(chess[sr][sc].team=='b')
                {
                    if(chess[dr][dc].team=='w')
                        if(dr==sr+1 && (dc==sc+1 || dc==sc-1))
                            return 1;
                        else 
                            return 0;
                    else if(sr==1)
                    {
                        if((dr==sr+1 || dr==sr+2) && dc==sc)
                            return 1;
                        else 
                            return 0;
                    } 
                    else if(dr==sr+1 && dc==sc)
                        return 1;
                    else 
                        return 0;
                }

                else
                {
                    if(chess[dr][dc].team=='b')
                        if(dr==sr-1 && (dc==sc+1 || dc==sc-1))
                            return 1;
                        else 
                            return 0;
                    else if(sr==6)
                    {
                        if((dr==sr-1 || dr==sr-2) && dc==sc)
                            return 1;
                        else 
                            return 0;
                    } 
                    else if(dr==sr-1 && dc==sc)
                        return 1;
                    else 
                        return 0;
                }

            case 1:
                if(dr==sr)
                {
                    if(forRow(sr,sc,dr,dc))
                        return 1;
                    else 
                        return 0;
                }
                else if(sc==dc)
                {
                    if(forColumn(sr,sc,dr,dc))
                        return 1;
                    else 
                        return 0;
                }
                else 
                    return 0;
        }
    }

    void pieceMove(int sr,int sc,int dr,int dc)
    {
        chess[dr][dc].pieceatxy=chess[sr][sc].pieceatxy;
        chess[dr][dc].team=chess[sr][sc].team;
        
            switch(chess[dr][dc].pieceatxy)
            {
                case 4:str[dr+1][dc+1]=((chess[dr][dc].team=='b')?'K':'k');
                        break;
                case 5:str[dr+1][dc+1]=((chess[dr][dc].team=='b')?'Q':'q');
                        break;
                case 3:str[dr+1][dc+1]=((chess[dr][dc].team=='b')?'B':'b');
                        break;
                case 2:str[dr+1][dc+1]=((chess[dr][dc].team=='b')?'N':'n');
                        break;
                case 1:str[dr+1][dc+1]=((chess[dr][dc].team=='b')?'R':'r');
                        break;
                case 6:str[dr+1][dc+1]=((chess[dr][dc].team=='b')?'P':'p');
                        break;
            }

        chess[sr][sc].pieceatxy=0;
        chess[sr][sc].team='n';
        str[sr+1][sc+1]='0';
    }

    void display()
    {
        cout<<endl<<endl;
        for(int i=0;i<9;i++)
        {

            for(int j=0;j<9;j++)
                cout<<str[i][j]<<"  ";
            cout<<endl;
            if(i==0)
                cout<<endl;
        }
        cout<<endl;

       /* for(int i=0;i<8;i++)
        {
            for(int j=0;j<8;j++)
                cout<<chess[i][j].pieceatxy<<" ";
            cout<<endl;
        }
        cout<<endl;
        for(int i=0;i<8;i++)
        {
            for(int j=0;j<8;j++)
                cout<<chess[i][j].team<<" ";
            cout<<endl;
        }*/
    }
};

int main()
{
    chessMethods obj;

    obj.initializeboard();

    int sr,sc,dr,dc;

    obj.display();
    int timer =0;

    cout<<"Lets START the game";

    label1:

    if(timer++%2==0)
    {
        cout<<"\nBLACK turn\n";
        ch='b';
    }
    else
    {
        cout<<"\nWHITE turn\n";
        ch='w';
    }

    cout<<"Enter source row and column:";
    cin>>sr>>sc;
    cout<<"\nEnter destination row and column:";
    cin>>dr>>dc;

    cout<<endl;

    if(sr>=8 && sr<=-1 && sc>=8 && sc<=-1 && dr>=8 && dr<=-1 && dc>=8 && dc<=-1 && sr==dr && sc==dc)
    {
        cout<<"\nWrong Input\n";
        timer-=1;
        goto label1;
    }
    int a,b,c,d;
        a=sr-1;
        b=sc-1;
        c=dr-1;
        d=dc-1;
    if(obj.check(a,b,c,d,ch))
    {
        
        if(obj.isMoveValid(a,b,c,d))
        {
           obj.pieceMove(a,b,c,d);

           obj.display();

        }
        else
        {
            cout<<"\nWrong Input\n";
            timer-=1;
            goto label1;
        }
    }
    else
    {
        cout<<"\nWrong Input\n";
        timer-=1;
        goto label1;
    }

    int flag=0;

    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
            if(chess[i][j].pieceatxy==4)
                flag++;
    }
    if(flag==2)
        goto label1;
    else
    {
        if(ch=='b')
           cout<<"\n BLACK WINS \n";
        else
            cout<<"\nWHITE WINS\n";
    }
}
