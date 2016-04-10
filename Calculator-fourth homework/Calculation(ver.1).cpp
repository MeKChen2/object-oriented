	#include <iostream>  
	#include <stack>  
	#include <string>
	#include <cstring> 
	using namespace std;  
	   
	class Calculation
	{  
	    private:  
	        stack<char> oper;
	        stack<double> shu;
	        double v,a,b;
	        char op; //运算符   
	    public:  
	        double calinput() //读取并计算表达式直到结束为止  
	        {  
	            do  
	            {  
	                readdata();
	            }  
	            while(readop());
	            calsurplus(); //处理栈中剩余的运算符 
	            cout << v << endl;
	            return 0;
	        }   
	          
	        void readdata() //读取数据 
	        {
	            while(!(cin>>v))  //判断读取数据是否正常 
	            {
	                cin.clear();
	                cin >> op;
	                oper.push(op);
	            }  
	            shu.push(v);
	            return;
	        }
	        
	        bool readop() //读取运算符   
	        {   
	             while((op = cin.get()) == ')')  
	             {  
	                while( oper.top() != '(' )  
	                {  
	                    b = shu.top(); 
	                    shu.pop();   
	                    a = shu.top();  
	                    shu.pop();  
	                    shu.push(cal(a, oper.top(), b)); //计算并入栈  
	                    oper.pop(); //取走运算符   
	                }     
	                oper.pop();   
	             }  
	             if(op == '\n')  
	             {  
	                return false;  
	             }  
	               
	             while(!oper.empty() && oper.top() != '(' && !com( op, oper.top()))  
	             {  
	                b = shu.top(); 
					shu.pop();  
	                a = shu.top(); 
					shu.pop();  
	                shu.push(cal( a, oper.top(), b )); //计算并入栈  
	                oper.pop(); //取走运算符    
	             }  
	               
	             oper.push(op);  
	             return true;  
	        }   
	          
	        void calsurplus()
	        {  
	            while(!oper.empty())  
	            {  
	                b = shu.top(); 
			shu.pop();  
	                a = shu.top(); 
			shu.pop();  
	                shu.push(cal( a, oper.top(), b )); //计算并入栈  
	                oper.pop(); //取走运算符   
	            }  
	
	            v = shu.top();  
	            shu.pop();  
	            return;  
	        }  
	        
	        double cal(double a, char op, double b)  
	        {  
				if(op=='+')
				    return a+b;
				else if(op=='-')
				    return a-b;
				else if(op=='*')
				    return a*b;
				else if(op=='/')
				    return a/b;
	        }  
	          
	        bool com(char c, char d) //若c比d优先级高返回true,否则返回false   
	        {  
	            if(c != '+' && c != '-' && d != '*' && d != '/')
	            	return true;
	            else
	            	return false;
	        }  
	          
	};  
	  
	int main()  
	{  
	    Calculation e;
	    e.calinput();
	    system("pause");  
	    return 0;  
	} 
