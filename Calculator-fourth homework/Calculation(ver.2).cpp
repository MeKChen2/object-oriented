#include <iostream>  
	#include <stack>   
	#include <string>  
	using namespace std;  
	const int SIZE = 100;  
	  
	bool isOperator( char op )  
	{  
	    switch(op)  
	    {  
	        case '+':  
	        case '-':  
	        case '*':  
	        case '/':  
	            return true;  
	        default:  
	            return false;  
	    }  
	}  
	  
	int check( char op )
	{  
	    int value = -1;  
	    switch(op)  
	    {   
	        case '(':  
	            value = 0;  
	            break;  
	        case '+':  
	        case '-':  
	            value = 1;  
	            break;  
	        case '*':  
	        case '/':  
	            value = 2;  
	            break;  
	    }  
	      
	    return value;  
	}    
	
	int change( string str, char a[SIZE], int &len ,int &sum )  
	{  
		// 中缀式转换为后缀式    	
	    stack<char> oper;   
	    oper.push('\0');  
	    int i = 0;  
	    int j = 0;  
	      
	    while( str[i] != '\0' )  
	    {  
	        if( str[i] >= '0' && str[i] <= '9' || str[i] == '.' )  
	        {  
	            a[j++] = str[i];  
	            len++;  
	        }   
	        else if( str[i] == '(' ) 
	        {  
	            oper.push(str[i]);  
	        }  
	        else if( str[i] == ')' )   
	        {  
	            while( oper.top() != '(' )  
	            {  
	               	a[j++] = oper.top();  
	                oper.pop();  
	                len++;  
	            }  
	            oper.pop(); 
	        }  
	        else if( i == 0 && (str[i] == '+' || str[i] == '-') && str[i+1] != 'a') //表明第一个数为正负号  
	        {  
	            a[j++] = str[i];  
	            len++;  
	        }
	        else if( i == 2 && (str[i] == '+' || str[i] == '-') && str[i-1] == 'a') //表明当出现"-a"时第三个数为正负号  
	        {  
	            a[j++] = str[i];  
	            len++;  
	        }
			else if( i == 0 && str[i] == '-' && str[i+1] == 'a' /*&& str[i+2] == ' '*/ )
	        {  
	            sum = 1;
	        }
	        else if( isOperator(str[i]) )  
	        {  
	            a[j++] = ' ';  //用空格隔开数  
	            len++;    
	            while( check(str[i]) <= check( oper.top() ) )  
	            {  
	                a[j++] = oper.top();  
	                oper.pop();  
	                len++;  
	            }  
	            oper.push(str[i]); 
	        }  
	        i++;  
	    }   
	      
	    while( oper.top() != '\0' )
	    {  
	        a[j++] = oper.top();  
	        oper.pop();  
	        len++;  
	    }  
	      
	    return 0;  
	}  
	  
	double read(char str[],int *i)    
	{    
	    double x=0.0;    
	    int k = 0;    
	    while(str[*i] >='0' && str[*i]<='9')  // 处理整数部分    
	    {    
	        x = x*10+(str[*i]-'0');    
	        (*i)++;    
	    }    
	    
	    if(str[*i]=='.') // 处理小数部分    
	    {    
	        (*i)++;    
	        while(str[*i] >= '0'&&str[*i] <='9')    
	        {    
	            x = x * 10 + (str[*i]-'0');    
	            (*i)++;    
	            k++;    
	        }    
	    }    
	    while(k!=0)    
	    {    
	        x /= 10.0;    
	        k--;    
	    }    
	    
	    return x;    
	}    
	  
	  
	double calculate( char post[SIZE] )  
	{  
		// 计算后缀表达式结果 
	    stack<double> stack;   // 操作数栈   
	    double x1 = 0;  
	    double x2 = 0;  
	    bool flag = false;  
	    int i = 0;  
	    double d = 0;  
	      
	    while( post[i] != '\0' )  
	    {  
	        if( post[i] >= '0' && post[i] <= '9' )  
	        {  
	            d =  read(post,&i);  
	            if(flag) // 第一个数为负数  
	            {  
	                d = -d;  
	                flag = false;  
	            }  
	            stack.push(d);  
	        }   
	        else if(post[i] == ' ' )  
	            i++;    
	        else if (post[i] =='+')    
	        {    
	            x2 = stack.top();    
	            stack.pop();  
	            x1 = stack.top();   
	            stack.pop();  
	            stack.push(x1+x2);    
	            i++;    
	        }    
	        else if( post[i] == '-' && i == 0 ) //表明第一个数为负数，方便计算-1+2*3  
	        {  
	            flag = true;  
	            i++;  
	        }  
	        else if (post[i] =='-')    
	        {    
	            x2 = stack.top();    
	            stack.pop();  
	            x1 = stack.top();  
	            stack.pop();   
	            stack.push(x1-x2);    
	            i++;    
	        }    
	        else if (post[i] =='*')    
	        {    
	            x2 = stack.top();    
	            stack.pop();  
	            x1 = stack.top();    
	            stack.pop();  
	            stack.push(x1*x2);    
	            i++;    
	        }    
	        else if (post[i] =='/')    
	        {    
	            x2 = stack.top();    
	            stack.pop();  
	            x1 = stack.top();    
	            stack.pop();  
	            stack.push(x1/x2);    
	            i++;    
	        }    
	    }    
	      
	    return stack.top();   
	}  
	  
	int main()  
	{  
	    string str = "";
		string str1 = ""; 
		int i = 0;
		int chang = 0;
	    char a[SIZE];   
	    cin >> str;
	    chang = str.size();
	    int len = 0;
		int sum = 0;  
	    change( str, a, len ,sum);  
	    a[len] = '\0';
		if(sum == 1)  
		{
			str1 = str.substr(2,chang-2); 
	    	cout << str1 << "= " << calculate(a) << endl;
		}
	    else
	    	cout << calculate(a) << endl;
	    system("pause");  
	    return 0;  
	} 
