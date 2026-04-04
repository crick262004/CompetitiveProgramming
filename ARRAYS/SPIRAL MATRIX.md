# SPIRAL MATRIX


void solve(){

    ll n; 
    cin >> n;

    *vvi* grid(n, *vi*(n, 0));
    int val = n*n;
    val--;
    int row = n;
    int col = n;
    int i = 0, j = 0;
    while(row > 0 && col > 0){
        f(c, col-1){
            grid[i][j] = val; val--;
            j++;
        }
        grid[i][j] = val; val--;
        i++;
        row--;
        if(row <= 0)
            break;
        
        
        
        f(r, row-1){
            grid[i][j] = val; val--;
            i++;
        }
        grid[i][j] = val; val--;
        j--;
        col--;
        if(col <= 0){break;}

        

        f(c, col-1){
            grid[i][j] = val; val--;
            j--;
        }
        grid[i][j] = val; val--;
        i--;
        row--;
        if(row <= 0)
            break;
        
        f(r, row-1){
            grid[i][j] = val; val--;
            i--;
        }
        grid[i][j] = val; val--;
        j++;
        col--;
    }
    f(i,n){
        cout << grid[i] << endl;
    }

}
