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
	long m = cast(long)inp.length;
	long n = cast(long)inp[0].length;
	writeln(m," ", n);
	long[] empty_rows;
	foreach(_; 0..m){
		empty_rows ~= 0;
	}
	foreach(i; 0..m){
		long gals = 0;
		foreach(j; 0..n){
			if(inp[i][j] == '#'){
				gals++;
			}
		}
		if(gals == 0){
			empty_rows[i] = 1;
		}
	}
	long[] empty_cols;
	foreach(_; 0..n){
		empty_cols ~= 0;
	}
	foreach(j; 0..n){
		long gals = 0;
		foreach(i; 0..m){
			if(inp[i][j] == '#'){
				gals++;
			}
		}
		if(gals == 0){
			empty_cols[j] = 1;
		}
	}
	long[] pref_row = [empty_rows[0]];
	long[] pref_col = [empty_cols[0]];
	foreach(i; 1..m){
		pref_row ~= empty_rows[i] + pref_row[$-1];
		write(pref_row[$ - 1], " ");
	}
	writeln();
	foreach(i; 1..n){
		pref_col ~= empty_cols[i] + pref_col[$-1];
		write(pref_col[$ - 1], " ");
	}
	writeln();
	long exp = 1000000;
	long[] xx;
	long[] yy;
	foreach(i; 0..m){
		foreach(j; 0..n){
			if(inp[i][j] == '#'){
				xx ~= i;
				yy ~= j;		
			}
		}	
	}
	long ans = 0;
	foreach(p1; zip(xx, yy)){
		foreach(p2; zip(xx, yy)){
			if(p1[0] == p2[0] && p1[1] == p2[1]){
				continue;
			}
			long diff = abs(p1[0] - p2[0]) + abs(p2[1] - p1[1]);
			diff += abs(pref_col[p2[1]] - pref_col[p1[1]]) * (exp - 1);
			diff += abs(pref_row[p2[0]] - pref_row[p1[0]]) * (exp - 1);
			writeln("(",p1[0], ",",p1[1],")","(",p2[0],",",p2[1],")","=",diff);
			ans += diff;
		}
	}

	writeln("Ans: ", ans/2);
}
