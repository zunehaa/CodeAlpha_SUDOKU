#include<iostream>
#include<vector>
#include<array>
#include<algorithm>
#include<iomanip>
#include<sstream>
#include<stdexcept>
using namespace std;

class SudokuSolver{
    static const int SIZE=9;
    static const int SUBGRID_SIZE=3;
    array<array<int,SIZE>,SIZE>grid;

    bool isValid(int row,int col,int num)const{
        for(int x=0;x<SIZE;++x){
            if(grid[row][x]==num){
                return false;
            }
        }

        for(int x=0;x<SIZE;++x){
            if(grid[x][col]==num){
                return false;
            }
        }

        int startRow=row-row%SUBGRID_SIZE;
        int startCol=col-col%SUBGRID_SIZE;
        for(int i=0;i<SUBGRID_SIZE;++i){
            for(int j=0;j<SUBGRID_SIZE;++j){
                if(grid[i+startRow][j+startCol]==num){
                    return false;
                }
            }
        }
        return true;
    }

    bool findEmptyCell(int& row,int& col)const{
        for(row=0;row<SIZE;++row){
            for(col=0;col<SIZE;++col){
                if(grid[row][col]==0){
                    return true;
                }
            }
        }
        return false;
    }

public:
    SudokuSolver(){
        for(auto& row:grid){
            row.fill(0);
        }
    }

    void loadGrid(const array<array<int,SIZE>,SIZE>&newGrid){
        grid=newGrid;
    }

    bool solve(){
        int row,col;
        if(!findEmptyCell(row,col)){
            return true;
        }

        for(int num=1;num<=SIZE;++num){
            if(isValid(row,col,num)){
                grid[row][col]=num;
                if(solve()){
                    return true;
                }
                grid[row][col]=0;
            }
        }
        return false;
    }

    void printGrid()const{
        cout<<"\n+-------+-------+-------+\n";
        for(int i=0;i<SIZE;++i){
            cout<<"| ";
            for(int j=0;j<SIZE;++j){
                if(grid[i][j]==0){
                    cout<<". ";
                }
                else{
                    cout<<grid[i][j]<<" ";
                }
                if((j+1)%SUBGRID_SIZE==0){
                    cout<<"| ";
                }
            }
            cout<<"\n";
            if((i+1)%SUBGRID_SIZE==0){
                cout<<"+-------+-------+-------+\n";
            }
        }
    }

    array<array<int,SIZE>,SIZE>getGrid()const{
        return grid;
    }

    bool validateInitialGrid()const{
        for(int row=0;row<SIZE;++row){
            array<bool,SIZE+1>seen{};
            for(int col=0;col<SIZE;++col){
                int num=grid[row][col];
                if(num!=0){
                    if(seen[num]){
                        return false;
                    }
                    seen[num]=true;
                }
            }
        }

        for(int col=0;col<SIZE;++col){
            array<bool,SIZE+1>seen{};
            for(int row=0;row<SIZE;++row){
                int num=grid[row][col];
                if(num!=0){
                    if(seen[num]){
                        return false;
                    }
                    seen[num]=true;
                }
            }
        }

        for(int boxRow=0;boxRow<SUBGRID_SIZE;++boxRow){
            for(int boxCol=0;boxCol<SUBGRID_SIZE;++boxCol){
                array<bool,SIZE+1>seen{};
                for(int row=0;row<SUBGRID_SIZE;++row){
                    for(int col=0;col<SUBGRID_SIZE;++col){
                        int num=grid[boxRow*SUBGRID_SIZE+row][boxCol*SUBGRID_SIZE+col];
                        if(num!=0){
                            if(seen[num]){
                                return false;
                            }
                            seen[num]=true;
                        }
                    }
                }
            }
        }
        return true;
    }
};

void readSudokuGrid(array<array<int,9>,9>& grid){
    cout<<"\n1. ENTER EACH ROW AS 9 SPACE-SEPRATED NUMBERS.\n\n";
    cout<<"2. USE 0 FOR EMPTY SPACE.\n\n";
    cout<<"ENTER SODUKO GRID:\n\n";
    for(int i=0;i<9;++i){
        while(true){
            try{
                string line;
                cout<<"ROW "<<(i+1)<<": ";
                getline(cin,line);

                istringstream iss(line);
                for(int j=0;j<9;++j){
                    if(!(iss>>grid[i][j])){
                        throw runtime_error("INVALID INPUT. ENTER 9 SPACE-SEPARATED NUMBERS FOR EACH ROW..");
                    }
                    if(grid[i][j]<0||grid[i][j]>9){
                        throw runtime_error("INVALID INPUT. NUMBERS MUST BE BETWEEN 0-9..");
                    }
                }
                break;
            } catch(const exception& e){
                cerr<<"Error: "<<e.what()<<"PLEASEE, TRY AGAIN..\n";
            }
        }
    }
}

int main(){
    try{
        SudokuSolver solver;
        array<array<int,9>,9>grid{};
        cout<<"-------------------------------\n";
        cout<<"|        SUDOKU SOLVER         |\n";
        cout<<"-------------------------------\n";

        readSudokuGrid(grid);
        solver.loadGrid(grid);

        if(!solver.validateInitialGrid()){
            cerr<<"\nError: CHECK FOR DUPLICATE NUMBERS IN ROWS OR COLUMNS, OR 3X3 SUB-GRIDS.\n";
            return 1;
        }

        cout<<"\nINITIAL SODUKO GRID:";
        solver.printGrid();
        cout<<"\nSOLVING...\n";
        if(solver.solve()){
            cout<<"\nSOLUTION:";
            solver.printGrid();
        }
        else{
            cout<<"\nSOLUTION DOES NOT EXIST..\n";
        }

    }
    catch(const exception& e){
        cerr<<"\nError: "<<e.what()<<"\n";
        return 1;
    }
    return 0;
}