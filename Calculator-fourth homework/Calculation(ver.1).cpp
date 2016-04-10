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
	        char op; //�����   
	    public:  
	        double calinput() //��ȡ��������ʽֱ������Ϊֹ  
	        {  
	            do  
	            {  
	                readdata();
	            }  
	            while(readop());
	            calsurplus(); //����ջ��ʣ�������� 
	            cout << v << endl;
	            return 0;
	        }   
	          
	        void readdata() //��ȡ���� 
	        {
	            while(!(cin>>v))  //�ж϶�ȡ�����Ƿ����� 
	            {
	                cin.clear();
	                cin >> op;
	                oper.push(op);
	            }  
	            shu.push(v);
	            return;
	        }
	        
	        bool readop() //��ȡ�����   
	        {   
	             while((op = cin.get()) == ')')  
	             {  
	                while( oper.top() != '(' )  
	                {  
	                    b = shu.top(); 
	                    shu.pop();   
	                    a = shu.top();  
	                    shu.pop();  
	                    shu.push(cal(a, oper.top(), b)); //���㲢��ջ  
	                    oper.pop(); //ȡ�������   
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
	                shu.push(cal( a, oper.top(), b )); //���㲢��ջ  
	                oper.pop(); //ȡ�������    
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
	                shu.push(cal( a, oper.top(), b )); //���㲢��ջ  
	                oper.pop(); //ȡ�������   
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
	          
	        bool com(char c, char d) //��c��d���ȼ��߷���true,���򷵻�false   
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
