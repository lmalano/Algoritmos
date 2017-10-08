<pre><p>
// prcd(o1,'(') = 0 para todo o1 != de ')'
// prcd(o1,')') = 1 para todo o1 != de '('
// prcd('(',o2) = 0 para todo 02
// prcd(o1,02)  = 1 para todo o1 &gt;= precendia que o2
int prcd(int o1,int o2)
{ if(o2=='(')
	 if(o1==')') return 1;
            else return 0;
  if(o2==')')
	 if(o1=='(') return 0;
		    else return 1;
  if(o1=='(') return 0;

  if((o1=='*')||(o1=='/')) return 1;
  if(((o1=='+')||(o1=='-'))&amp;&amp;((o2=='+')||(o2=='-'))) return 1;
						                        else return 0;
}

int main()
{
    string cadena,pf;
    Pila *p=new Pila();
// Chequear parentesis
// conversion a PostFijo
    
      cout&lt;&lt;&quot;\n inicio conversion a POSTFIJO:&quot;&lt;&lt;cadena&lt;&lt;endl;
      int i,j,k=0;
      char d,p1;
      for(j=0;j&lt;cadena.length();j++)
      { d=cadena.at(j); cout&lt;&lt;&quot;d= &quot;&lt;&lt;d&lt;&lt;endl;
	    if ((d&gt;='0')&amp;&amp;(d&lt;='9'))
	       {pf[k]=d;k++; cout&lt;&lt;&quot;    pf= &quot;;for(i=0;i&lt;k;i++)cout&lt;&lt;pf[i];cout&lt;&lt;endl;}
	    else
	       { while((!p-&gt;pilavacia())&amp;&amp;(prcd(p-&gt;tope(),d)))
	             {p1=p-&gt;tope();p-&gt;pop();pf[k]=p1;k=k+1;cout&lt;&lt;&quot;    pf= &quot;;for(i=0;i&lt;k;i++)cout&lt;&lt;pf[i];cout&lt;&lt;endl;}
	         if((p-&gt;pilavacia())||(d!=')')) p-&gt;push(d);
			 else p-&gt;pop();
	    }
      }
      while(!p-&gt;pilavacia())
	      {p1=p-&gt;tope();p-&gt;pop();pf[k]=p1;k++;}
      pf[k]='\0';
      cout&lt;&lt;&quot;\n TERMINE la conversion a POSTFIJO: &quot;;
      for(i=0;i&lt;=k;i++){cout&lt;&lt;pf[i]; cadena[i]=pf[i];}
  int o1,o2;
  for(int i=0;i&lt;k;i++){ 
     if(cadena.at(i)&gt;='0' &amp;&amp; cadena.at(i)&lt;='9')
         p-&gt;push(cadena.at(i)-'0');
     if(cadena.at(i)=='+'){
               o2=p-&gt;tope(); p-&gt;pop();
               o1=p-&gt;tope(); p-&gt;pop(); 
               p-&gt;push(o1+o2);
     }
     if(cadena.at(i)=='-'){
               o2=p-&gt;tope(); p-&gt;pop();
               o1=p-&gt;tope(); p-&gt;pop(); 
               p-&gt;push(o1-o2);
     }        
     if(cadena.at(i)=='*'){
               o2=p-&gt;tope(); p-&gt;pop();
               o1=p-&gt;tope(); p-&gt;pop(); 
               p-&gt;push(o1*o2);
     }              
  }
  cout&lt;&lt;&quot;resultado= &quot;&lt;&lt;p-&gt;tope()&lt;&lt;endl;
 
     cout&lt;&lt;endl;
     system(&quot;PAUSE&quot;);
     return 0;
}
</p></pre>