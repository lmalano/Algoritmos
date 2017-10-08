<pre><p>/*
 *      set_array.cpp
 *      
 */

#define UNIVERSE 32
#define BYTE_LEN 8
#define ARRAY_LEN (UNIVERSE / BYTE_LEN)


#include &lt;iostream&gt;
#include &lt;sstream&gt;

using namespace std;

typedef struct arr_pos{
	int pos;
	int offset;
} arr_pos;

arr_pos postoarra_pos (int p) {
	arr_pos ret;
	ret.pos= ((p-1) / BYTE_LEN ) ;
	ret.offset=((p-1) % BYTE_LEN );
	return ret;
}

class set_array {
	private:
	   unsigned char data[ARRAY_LEN];
	public:
	   set_array() {fill_n(data,ARRAY_LEN,0);};
	   unsigned char * get_data() {return data;};
	   void set_on(int pos) ;
	   void set_off(int pos) ;
	   bool esta(int pos);
	   set_array *union_set(set_array *b);
	   set_array *intersec(set_array *b);
	   set_array *dif(set_array *b);
	   string toPrint();
};

void set_array::set_on(int pos) {
	arr_pos aux = postoarra_pos(pos);
	data[aux.pos] |= (unsigned char) (1 &lt;&lt; aux.offset);
}

void set_array::set_off(int pos) {
	arr_pos aux = postoarra_pos(pos);
	unsigned char mask=(1 &lt;&lt; aux.offset);
	mask = ~mask;
	data[aux.pos] &amp;= mask;
}

bool set_array::esta(int pos) {
	arr_pos aux = postoarra_pos(pos);
	unsigned char mask=(1 &lt;&lt; aux.offset);
	return (data[aux.pos] &amp; mask);
}

set_array *set_array::union_set(set_array *b){
	set_array *c=new set_array();
	for (int i=0;i&lt;ARRAY_LEN;i++) {
		(c-&gt;get_data())[i]= data[i] | (b-&gt;get_data())[i];
    }
	return c;
}

set_array *set_array::intersec(set_array *b){
	set_array *c=new set_array();
	for (int i=0;i&lt;ARRAY_LEN;i++) {
		(c-&gt;get_data())[i]= data[i] &amp; (b-&gt;get_data())[i];
    }
	return c;
}

set_array *set_array::dif(set_array *b){
	set_array *c=new set_array();
	for (int i=0;i&lt;ARRAY_LEN;i++) {
		(c-&gt;get_data())[i]= data[i] &amp; ~(b-&gt;get_data())[i];
    }
	return c;
}

string set_array::toPrint() {
    std::ostringstream stm;
	for (int i=ARRAY_LEN-1;i&gt;=0;i--) {
       stm &lt;&lt; &quot; &quot;;
       stm.width(2);
       stm.fill('0');
       stm &lt;&lt;hex&lt;&lt;(int)data[i];
	}
    stm &lt;&lt; endl;
    return stm.str();
}

int main(int argc, char** argv)
{
	set_array *a=new set_array();
	set_array *b=new set_array();
	a-&gt;set_on(8);
	a-&gt;set_on(5);
	a-&gt;set_on(1);
	a-&gt;set_on(16);
	a-&gt;set_on(15);
	a-&gt;set_on(32);
	cout &lt;&lt; a-&gt;esta(8)&lt;&lt;endl;
	cout &lt;&lt; a-&gt;esta(9)&lt;&lt;endl;
	b-&gt;set_on(4);
	b-&gt;set_on(7);
	b-&gt;set_on(1);
	b-&gt;set_on(6);
	b-&gt;set_on(32);
	cout &lt;&lt; b-&gt;esta(8)&lt;&lt;endl;
	cout &lt;&lt; b-&gt;esta(6)&lt;&lt;endl;
	cout &lt;&lt; a-&gt;toPrint();
	cout &lt;&lt; b-&gt;toPrint();
	cout &lt;&lt; (a-&gt;union_set(b))-&gt;toPrint();
	cout &lt;&lt; (a-&gt;intersec(b))-&gt;toPrint();
	cout &lt;&lt; (a-&gt;dif(b))-&gt;toPrint();
	return 0;
}
</p></pre>