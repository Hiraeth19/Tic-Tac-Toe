
# include <iostream>
using namespace std;
int frequency[9];
 char arr[9] = {'1','2','3','4','5','6','7','8','9'};
class level_1
{     int p1[5],p2[4];

       public:
    void out( )
    {   cout << "***************"<< endl;
        for(int x = 0; x <9;x += 3)
            cout <<" * "<< arr[x] << " * "<< arr[x + 1] << " * "<< arr[x + 2] << " * "<< endl;
         cout << "***************"<< endl;

    }
    bool frq(int a)
    {   if(a > 9 || a < 0){
            cout<<"SORRY, out of bounds, try choosing a value between 1 to 9"<< endl;
             cout << "--------------------------------------------------------------"<< endl;
            return false;
    }
         if(frequency[a] == 1)
       {
           cout<< "SORRY already chosen, kindly chose a different number"<<endl;
           cout << "--------------------------------------------------------------"<< endl;
            return false;
       }
       else
       {
        frequency[a] = 1;
        return true;
       }
    }
   int input(int k, int turn)
   {    bool fr = true;
        int temp;
        cout<< "Enter your choice"<<endl;
        cin>> temp;                             //check k
         fr = frq(temp);
        while(!fr)
       { cout<< "Enter your choice"<<endl;
        cin>> temp;                             //check k
         fr = frq(temp);
       }
        if(turn == 1)
              {     //p1[k] = temp;
                  arr[ temp - 1] = 'X';

               }
        if (turn == 2)
              {   // p2[k] = temp;
                 arr[temp - 1] = 'O';

              }
                cout << "--------------------------------------------------------------"<< endl;
    
        
            
   }

   bool check()
   {   
        int x = 0;
        cout<< arr[x]<<endl;
        if(arr[0] == 'X' && arr[1] == 'X' && arr[2] == 'X')
            return 1;
        if(arr[0] == 'X' && arr[3] == 'X' && arr[6] == 'X')
            return 1;
        if(arr[0] == 'X' && arr[4] == 'X' && arr[8] == 'X')
            return 1;
        if(arr[1] == 'X' && arr[4] == 'X' && arr[7] == 'X')
            return 1;
        if(arr[2] == 'X' && arr[5] == 'X' && arr[8] == 'X')
            return 1;
        if(arr[2] == 'X' && arr[4] == 'X' && arr[6] == 'X')
            return 1;
        if(arr[3] == 'X' && arr[4] == 'X' && arr[5] == 'X')
            return 1;
        if(arr[6] == 'X' && arr[7] == 'X' && arr[8] == 'X')
            return 1;
            

             if(arr[0] == 'O' && arr[1] == 'O' && arr[2] == 'O')
            return 1;
        if(arr[0] == 'O' && arr[3] == 'O' && arr[6] == 'O')
            return 1;
        if(arr[0] == 'O' && arr[4] == 'O' && arr[8] == 'O')
            return 1;
        if(arr[1] == 'O' && arr[4] == 'O' && arr[7] == 'O')
            return 1;
        if(arr[2] == 'O' && arr[5] == 'O' && arr[8] == 'O')
            return 1;
        if(arr[2] == 'O' && arr[4] == 'O' && arr[6] == 'O')
            return 1;
        if(arr[3] == 'O' && arr[4] == 'O' && arr[5] == 'O')
            return 1;
        if(arr[6] == 'O' && arr[7] == 'O' && arr[8] == 'O')
            return 1;
    

   }
   friend int flow(level_1 p_1, level_1 p_2);


};
class level_2
{
    public:

};
int flow(level_1 p_1, level_1 p_2)
{   
   for(int x = 0;x <=5; x++ )
  {  cout << "Player 1:";
    p_1.input(x,1);
    p_1.out();
    if(x >= 2)
    {   cout<< "hey"<<endl;
        int ans_1 = p_1.check();
        if (ans_1 == true)
            return 1;
    }
    cout << "Player 2:";
    p_2.input(x,2);
    p_2.out();
    if(x >= 2)
    {   cout<<"ia am here"<<endl;
        int ans_2 = p_2.check();
        if(ans_2 == true)
            return 2;
    }
    if(x == 4)
      return 3;
}
}

int main()
{   int level;
    cout << "Welcome to TIC TAC TOE"<< endl;
     cout<< "Enter level"<<endl;
     cin>> level;
     switch(level)
     {
     case 1:
        level_1 p_1;
        level_1 p_2;
       int ans =  flow(p_1,p_2);
       if(ans == 1)
        cout<< "Player 1 wins";
       if (ans == 2)
        cout << "Player 2 wins";
       if(ans == 3)
        cout << "Draw";

     }
   return 0;
}
