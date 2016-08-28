#include<vik.h>
#include<conio.h>
#include<windows.h>

void show(char a[3][3])
{
	for(int i=0;i<3;i++)
	{   
	   for(int j=0;j<3;j++)
	   { if(j<2)
	   cout<<a[i][j]<<" | ";
       else
	   cout<<a[i][j]; 
	   } 
	  if(i<2)
	  cout<<endl<<"  |   |  "<<"\n---------"<<endl;
	  else
	  cout<<endl;
	}
}
char check(char a[3][3])
{
	if(a[0][0]==a[0][1]&&a[0][1]==a[0][2])
	return (a[0][0]);
	else
	if(a[0][0]==a[1][0]&&a[1][0]==a[2][0])
	return(a[0][0]);
	else
	if(a[1][0]==a[1][1]&&a[1][1]==a[1][2])
	return (a[1][0]);
	else
	if(a[2][0]==a[2][1]&&a[2][1]==a[2][2])
	return (a[2][0]);
	else
	if(a[0][0]==a[1][1]&&a[1][1]==a[2][2])
	return (a[0][0]);
	else
	if(a[0][1]==a[1][1]&&a[1][1]==a[2][1])
	return (a[0][1]);
	else
	if(a[0][2]==a[1][2]&&a[1][2]==a[2][2])
	return (a[0][2]);
	else
	if(a[0][2]==a[1][1]&&a[1][1]==a[2][0])
	return (a[0][2]);
	else
	return ('\0');
}
int checkavail(char a[3][3],int p)
{   int i,j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(a[i][j]-48==p)
			return 1;
		}
	}
	return 0;
}
int random()
{
	int r=rand()%9+1;
	return r;
}
int check2(char a[3][3])
{
	if(a[0][0]==a[0][1]&&checkavail(a,3))
	return 3;
	else
	if(a[0][0]==a[0][2]&&checkavail(a,2))
	return 2;
	else
	if(a[0][1]==a[0][2]&&checkavail(a,1))
	return 1;
	else
	if(a[1][0]==a[1][1]&&checkavail(a,6))
	return 6;
	else
	if(a[1][1]==a[1][2]&&checkavail(a,4))
	return 4;
	else
	if(a[1][0]==a[1][2]&&checkavail(a,5))
	return 5;
	else
	if(a[2][0]==a[2][1]&&checkavail(a,9))
	return 9;
	else
	if(a[2][1]==a[2][2]&&checkavail(a,7))
	return 7;
	else
	if(a[2][0]==a[2][2]&&checkavail(a,8))
	return 8;
	else
	if(a[0][0]==a[1][0]&&checkavail(a,7))
	return 7;
	else
	if(a[0][0]==a[2][0]&&checkavail(a,4))
	return 4;
	else
	if(a[1][0]==a[2][0]&&checkavail(a,1))
	return 1;
	else
	if(a[0][1]==a[1][1]&&checkavail(a,8))
	return 8;
	else
	if(a[1][1]==a[2][1]&&checkavail(a,2))
	return 2;
	else
	if(a[0][1]==a[2][1]&&checkavail(a,5))
	return 5;
	else
	if(a[0][2]==a[1][2]&&checkavail(a,9))
	return 9;
	else
	if(a[1][2]==a[2][2]&&checkavail(a,3))
	return 3;
	else
	if(a[0][2]==a[2][2]&&checkavail(a,6))
	return 6;
	else
	if(a[0][0]==a[1][1]&&checkavail(a,9))
	return 9;
	else
	if(a[0][0]==a[2][2]&&checkavail(a,5))
	return 5;
	else
	if(a[1][1]==a[2][2]&&checkavail(a,1))
	return 1;
	else
	if(a[0][2]==a[1][1]&&checkavail(a,7))
	return 7;
	else
	if(a[0][2]==a[2][0]&&checkavail(a,5))
	return 5;
	else
	if(a[1][1]==a[2][0]&&checkavail(a,3))
	return 3;
	else
	return 0;
	
}
int check3(char a[3][3])
{
	if(a[0][0]==a[2][1])
	return 4;
	if(a[0][0]==a[1][2])
	return 2;
	if(a[0][2]==a[2][1])
	return 6;
	if(a[0][2]==a[1][0])
	return 2;
	if(a[2][0]==a[0][1])
	return 4;
	if(a[2][0]==a[1][2])
	return 8;
	if(a[2][2]==a[0][1])
	return 6;
	if(a[2][2]==a[1][0])
	return 8;
	if(a[0][0]==a[2][2])
	return 4;
	if(a[0][2]==a[2][0])
	return 6;
	if(a[0][1]==a[1][0])
	return 1;
	if(a[0][1]==a[1][2])
	return 3;
	if(a[1][0]==a[2][1])
	return 7;
	if(a[2][1]==a[1][2])
	return 9;
	else
	return 0;
}
int comTurn(char a[3][3],int turn)
{  int i=0;
	if(turn==2||turn==1)
	{
		if(checkavail(a,5))
		return 5;
		else
		while(i==0)
		{
			int t=random();
			if(t==1||t==3||t==7||t==9)
			{
				if(checkavail(a,t))
				{ i=1;
				return t;
			    }
			}
		}
	}
	else
	if(turn==4||turn==3)
	{   
		int t=check3(a);
		if(t>0)
		{
			return t;
		}
		else
		{
			t=check2(a);
			if(t>0)
			return t;
		   else
		{  
		  i=0;
		while(i==0)
		{
			int t=random();
			if(t==1||t==3||t==7||t==9)
			{
				if(checkavail(a,t))
				{ i=1;
				return t;
			    }
			}
		}
     	}
	    }
    }
	else
	{ int t=check2(a);
	 if(t>0)
	 return t;
	 else
	 { i=0;
	 	while(i==0)
		{
			int t=random();
				if(checkavail(a,t))
				{ i=1;
				return t;
			    }
		}
	 } 	
	}
}
int main()
{   clear();
    int y=1,c=0,pl=0,d=0;
    char p1,com;
	clear();
	cout<<"Enter Character for player 1 : ";
	cin>>p1;
	cout<<"\nEnter Character for Computer : ";
	cin>>com;
    while(y==1)
    { y--;
    if((c+pl+d)%2==0)
    {
	char arr[3][3]={49,50,51,52,53,54,55,56,57};
	for(int i=1;i<=9;i++)
	{  clear();
	   setColor(14); 
	   show(arr); 
	    if(i%2==1)
	       { setColor(6);
	    	cout<<"Player 1- Enter position: "<<endl;  
	    	int p;
	    	cin>>p;
	    	if(checkavail(arr,p))
	    	{
	    	switch (p)
	    	{
	    		case 1:
	    			arr[0][0]=p1;
	    			break;
	    		case 2:
				    arr[0][1]=p1;
					break;	
				case 3:
	    			arr[0][2]=p1;
	    			break;
	    		case 4:
				    arr[1][0]=p1;
					break;	
				case 5:
	    			arr[1][1]=p1;
	    			break;
	    		case 6:
				    arr[1][2]=p1;
					break;	
				case 7:
	    			arr[2][0]=p1;
	    			break;
				case 8:
	    			arr[2][1]=p1;
	    			break;
	    		case 9:
				    arr[2][2]=p1;
					break;
				default:
				    cout<<"You have Entered wrong value - GAME OVER";						
	    	}	
	    	if(p1==check(arr))
	    	{ clear();
	    	 show(arr);
		   cout<<"\nPLAYER 1 WINS"<<endl;
		   pl++;
	        break;
			}
		    }
		    else
		    break;
	     clear();
	     setColor(14);
		 show(arr);
          }
          else
          {  
           setColor(3);
	    	int p=comTurn(arr,i);
	    	if(checkavail(arr,p))
	    	{
	    	switch (p)
	    	{
	    		case 1:
	    			arr[0][0]=com;
	    			break;
	    		case 2:
				    arr[0][1]=com;
					break;	
				case 3:
	    			arr[0][2]=com;
	    			break;
	    		case 4:
				    arr[1][0]=com;
					break;	
				case 5:
	    			arr[1][1]=com;
	    			break;
	    		case 6:
				    arr[1][2]=com;
					break;	
				case 7:
	    			arr[2][0]=com;
	    			break;
				case 8:
	    			arr[2][1]=com;
	    			break;
	    		case 9:
				    arr[2][2]=com;
					break;
				default:
				    cout<<"You have Entered wrong value - GAME OVER";						
	    	}
		    }
		    else
		    break;
	      if(com==check(arr))
	      { clear();
	        show(arr);
		    cout<<"COM WINS"<<endl;
		    c++;
          break;
		  }
		  }
		  if(p1==check(arr))
		  { 
		  	break;
		  } else
		  if(com==check(arr))
		  {
		  	break;
		  }
	}	
	setColor(10);
	if(p1!=check(arr)&&com!=check(arr))
	{
	cout<<"\nMATCH DRAW"<<endl;
    d++;
	}
	cout<<"Wins: "<<"\n  COM- "<<c<<"    PLAYER- "<<pl<<"    DRAW- "<<d<<"\n\n Enter 1 to play again: ";
    cin>>y;
	}else
	{char arr[3][3]={49,50,51,52,53,54,55,56,57};
	for(int i=1;i<=9;i++)
	{  clear();
	   setColor(14); 
	   show(arr); 
	    if(i%2==0)
	       { setColor(6);
	    	cout<<"Player 1- Enter position: "<<endl;  
	    	int p;
	    	cin>>p;
	    	if(checkavail(arr,p))
	    	{
	    	switch (p)
	    	{
	    		case 1:
	    			arr[0][0]=p1;
	    			break;
	    		case 2:
				    arr[0][1]=p1;
					break;	
				case 3:
	    			arr[0][2]=p1;
	    			break;
	    		case 4:
				    arr[1][0]=p1;
					break;	
				case 5:
	    			arr[1][1]=p1;
	    			break;
	    		case 6:
				    arr[1][2]=p1;
					break;	
				case 7:
	    			arr[2][0]=p1;
	    			break;
				case 8:
	    			arr[2][1]=p1;
	    			break;
	    		case 9:
				    arr[2][2]=p1;
					break;
				default:
				    cout<<"You have Entered wrong value - GAME OVER";						
	    	}	
	    	if(p1==check(arr))
	    	{ clear();
	    	 show(arr);
		   cout<<"\nPLAYER 1 WINS"<<endl;
		   pl++;
	        break;
			}
		    }
		    else
		    break;
	     clear();
	     setColor(14);
		 show(arr);
          }
          else
          {  
           setColor(3);
	    	int p=comTurn(arr,i);
	    	if(checkavail(arr,p))
	    	{
	    	switch (p)
	    	{
	    		case 1:
	    			arr[0][0]=com;
	    			break;
	    		case 2:
				    arr[0][1]=com;
					break;	
				case 3:
	    			arr[0][2]=com;
	    			break;
	    		case 4:
				    arr[1][0]=com;
					break;	
				case 5:
	    			arr[1][1]=com;
	    			break;
	    		case 6:
				    arr[1][2]=com;
					break;	
				case 7:
	    			arr[2][0]=com;
	    			break;
				case 8:
	    			arr[2][1]=com;
	    			break;
	    		case 9:
				    arr[2][2]=com;
					break;
				default:
				    cout<<"You have Entered wrong value - GAME OVER";						
	    	}
		    }
		    else
		    break;
	      if(com==check(arr))
	      { clear();
	        show(arr);
		    cout<<"COM WINS"<<endl;
		    c++;
          break;
		  }
		  }
		  if(p1==check(arr))
		  { 
		  	break;
		  } else
		  if(com==check(arr))
		  {
		  	break;
		  }
	}	
	setColor(10);
	if(p1!=check(arr)&&com!=check(arr))
	{
	cout<<"\nMATCH DRAW"<<endl;
    d++;
	}
	cout<<"Wins: "<<"\n  COM- "<<c<<"    PLAYER- "<<pl<<"    DRAW- "<<d<<"\n\n Enter 1 to play again: ";
    cin>>y;
    }
	}
	return 0;
}
