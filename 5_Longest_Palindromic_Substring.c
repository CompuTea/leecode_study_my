code : 
#define DP_SIZE 1000
bool dp[DP_SIZE][DP_SIZE]={0};

char ans[DP_SIZE];
char * longestPalindrome(char * s){
	int s_len= strlen(s);
	int i, j;
	int start=0, end=0, len_max=0, len=0;

	for(i=0; i<s_len; i++) {
		dp[i][i]=1;

		start=i;
		end=i;
		if((end-start) > len_max) {
			len_max = (end-start);
		}
	}
	// show_DP();
	for(i=0; i<(s_len-1); i++) {
		if(s[i] == s[i+1]) {
			dp[i][i+1]=1;

			start=i;
			end=(i+1);
			if((end-start) > len_max) {
				len_max = (end-start);
			}
		}
	}	
	// show_DP();
	i=0;
	j=2;
	int loop=2;
	while((j-i)<s_len) {
		if(j>=s_len) {
			i=0;
			loop++;
			j=loop;
		}

		if((s[i] == s[j]) && (dp[i+1][j-1] == 1)) {
			dp[i][j]=1;
			// show_DP();			
			if((j-i+1) > len_max) {
				start=i;
				end=j;
				len_max = (end-start+1);
			}

		}

		i++;
		j++;
	}
	// show_DP();
	
	memcpy(ans, s+start, (end-start+1));	
	ans[(end-start)+1]='\0';

	return ans;
}
