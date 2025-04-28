#include<bits/stdc++.h>
 bool ifknowns(const vector<vector<int>>& M, int a, int b){
	if(M[a][b]==1){
		return true;
	}
	else{
		return false;
	}
}
int findCelebrity(int n) {
 	vector<vector<int>> M(n, vector<int>(n));

	stack<int> s;

  for(int i=0; i<n; i++){
		s.push(i);
	}
	//finding celeb candidate
	while(s.size()>1){
		int a=s.top();
		s.pop();
		int b=s.top();
		s.pop();
		if(ifknowns(M,a,b)){
			s.push(b);
		}
		else{
			s.push(a);
		}
	}
	int celebcondidate = s.top();
	//checking if candidate is celeb
	int countzero = 0;
	for(int i=0;i<n;i++){
		if(M[celebcondidate][i]==0){
			countzero++;
		}
	}
	bool rowcheck = false;
	if(countzero == n){
		rowcheck = true;
	}
	int countone=0;
	for(int i=0;i<n;i++){
		if(M[i][celebcondidate]==1){
			countone++;
		}
	}
	bool colcheck = false;
	if(countone == n-1){
		colcheck = true;
	}
	if(colcheck && rowcheck ){
		return celebcondidate;
	}
	else{
		return -1;
	}
}
