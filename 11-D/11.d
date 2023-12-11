module hello;
import std.math;
import std.stdio;
import std.array;
import std.range : zip;
import std.algorithm : map;
void main(){
	string[] inp1;
	string tmp;
	readf("%s", tmp);
	inp1 = tmp.split('\n');
	inp1.popBack();
	char[][] inp;
	foreach(ss; inp1){
		char[] inpx;
		foreach(sss; ss){
			inpx ~= sss;
		}
		inp ~= inpx;
	}
	int m = cast(int)inp.length;
	int n = cast(int)inp[0].length;
	writeln(m," ", n);
	int[] empty_rows;
	foreach(i; 0..m){
		int gals = 0;
		foreach(j; 0..n){
			if(inp[i][j] == '#'){
				gals++;
			}
		}
		if(gals == 0){
			empty_rows ~= i;
		}
	}
	int[] empty_cols;
	foreach(j; 0..n){
		int gals = 0;
		foreach(i; 0..m){
			if(inp[i][j] == '#'){
				gals++;
			}
		}
		if(gals == 0){
			empty_cols ~= j;
		}
	}
	foreach_reverse(j; empty_cols){
		foreach(i; 0..m){
			inp[i].insertInPlace(j, ['.']);
		}
	}
	n = cast(int)inp[0].length;
	char[] empty_row = [];
	foreach(_; 0..n){
		empty_row ~= '.';
	}
	foreach_reverse(i; empty_rows){
		inp.insertInPlace(i, [empty_row]);
	}
	writeln();
	foreach(s; inp){
		writeln(s);
	}
	m = cast(int)inp.length;
	writeln( m, n);
	int[] xx;
	int[] yy;
	foreach(i; 0..m){
		foreach(j; 0..n){
			write(j, ' ');
			if(inp[i][j] == '#'){
				xx ~= i;
				yy ~= j;
			}
		}
		writeln();
	}
	int ans = 0;
	foreach(p1; zip(xx, yy)){
		foreach(p2; zip(xx, yy)){
			if(p1[0] == p2[0] && p1[1] == p2[1]){
				continue;
			}
			int diff = abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
			writeln("(",p1[0], ",",p1[1],")","(",p2[0],",",p2[1],")","=",diff);
			ans += diff;	
		}
	}
	writeln("Ans: ", ans/2);
}
