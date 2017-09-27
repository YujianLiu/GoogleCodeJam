//
//  main.cpp
//  GoogleCodeJam
//
//  Created by yujian liu on 4/6/17.
//  CopyRb © 2017 yujian liu. All Rbs reserved.
//

#include "Header.h"

map<string,int> cache;
int testtidy(int n)
{
    int temp=0,max=n%10;
    while(n>0)
    {
        temp=n%10;
        if(max<temp)
            return 0;
        max=temp;
        n=n/10;
    }
    return 1;
}

void TidyNums()
{
    int t;
    cin >> t;
    for(int i=0;i<t;i++)
    {
        int n;
        cin >> n;
        cout<<"Case #"<<i+1<<": ";
        if(n<10)
        {
            cout<<n<<endl;
        }
        else
        {
            for(int i=n;i>0;i--)
            {
                if(testtidy(i)==1)
                {cout<< i <<endl;
                    break;}
            }
        }
        
    }
}

void TidyNums_large()
{
    int t;
    cin >> t;
    for(int i=0;i<t;i++)
    {
        string s;
        cin >> s;
        cout << "Case #"<<i+1<<": ";
        int len = s.size();
        if(len==1)
            {
                cout<<s<<endl;
            }
        else
        {
            
            for(int j=len-2;j>=0;j--)
            {
                if(s[j]>s[j+1])
                {
                    s[j]-=1;
                    for(int k=j+1;k<len;k++)
                    {s[k]='9';}
                }
            }
            while(s[0]=='0')
            {
                s.erase(s.begin());
            }
            cout << s<<endl;
        }
    }
}
void Bathroom_Stalls()
{
    int t;
    cin >> t;
    for(int i = 0;i < t;i++)
    {
        int n, k;
        cin >> n >> k;
        for(int i=0;i<t;i++)
        {
            cout << "Case #"<<i+1<<": ";
            
        }
        
        
    }
}
void oversize_Pancake_Oven()
{
    ofstream myfile;
    myfile.open("/Users/yujianliu/Downloads/sub-1.out");
    int t, n, m, flag=0;
    cin >> t;  // read t. cin knows that t is an int, so it reads it as such.
    for(auto i=0;i<t;i++)
    {
        string s;
        int res=0;
        cin >> s >> n;
        for(m=0;m<=s.size()-n;m++)
        {
            if(s[m]=='-')
            {
                res++;
                for(int k=0;k<n;k++)
                {
                    if(s[k+m]=='-')
                    {s[k+m]='+';}
                    else
                    {s[k+m]='-';}
                }
            }
        }
        myfile <<"Case #"<<i+1<<": ";
        while(m<s.size())
        {
            if(s[m]=='-')
            {
                flag=1;
            }
            m++;
        }
        m=0;
        if(flag==1)
        {
            myfile<<"IMPOSSIBLE"<<endl;
        }
        else
            myfile<<res<<endl;
        res=0;
        flag =0;
    }
}
void oversize_Pancake_Oven_opt()
{
    ifstream input;
    ofstream output;
    input.open("/Users/yujianliu/Downloads/A-large-practice (3).in");
    output.open("/Users/yujianliu/Downloads/sub-1.out");
    int t;
    input >> t;
    for(int i=1;i<=t;i++)
    {
        string s;
        int n;
        input >> s >> n;
        int len = s.size(),flip_count=0, res=0;
        vector<int> memo(len,0);
        
        output << "Case #"<<i <<": ";
        for(int j=0;j<len;j++)
        {
            flip_count+=memo[j];
            memo[j]=flip_count;
            if((s[j]=='-'&&flip_count%2==0)||(s[j]=='+'&&flip_count%2!=0))
            {
                if(j<len-n+1)
                {
                    flip_count++;
                    res++;
                    if(j<len-n)
                    memo[j+n]-=1;
                }
                else
                {
                    output << "IMPOSSIBLE" <<endl;
                    break;
                }
                
            }
            memo[j]=flip_count;
            if(j==len-1)
            output<< res <<endl;
        }
        
    }
    input.close();
    output.close();
}

void bathroom_Stalls_1()
{
    ifstream input;
    ofstream output;
    input.open("/Users/yujianliu/Downloads/C-small-practice-1.in");
    output.open("/Users/yujianliu/Downloads/sub-1.out");
    int t;
    input >> t;
    for(int i=1;i<=t;i++)
    {
        int n, k;
        input >> n >> k;
        set<int> stalls_Occupied;
        stalls_Occupied.insert(0);
        stalls_Occupied.insert(n+1);
        output << "Case #"<< i <<": ";
        for(int i=0;i<k;i++)
        {
            int min_Dis=0, max_Dis=0, index=0;
            for(int j=1;j<=n;j++)
            {
                auto it = stalls_Occupied.find(j);
                if(it==stalls_Occupied.end())
                {
                    int Lb = *(--stalls_Occupied.lower_bound(j)), Rb = *stalls_Occupied.upper_bound(j);
                    if(min_Dis<min(j-Lb,Rb-j))
                    {
                        min_Dis = min(j-Lb,Rb-j);
                        index = j;
                    }
                    else if(min_Dis == min(j-Lb,Rb-j))
                    {
                        if(max_Dis < max(j-Lb,Rb-j))
                        {
                            max_Dis = max(j-Lb,Rb-j);
                            index = j;
                        }
                    }
                }
            }
            stalls_Occupied.insert(index);
            if(i==k-1)
                output<< max_Dis-1 << " "<<min_Dis-1<<endl;
        }
        
    }
    
    input.close();
    output.close();

}

void Alphabet_Cake()
{
    ifstream input;
    ofstream output;
    input.open("/Users/yujianliu/Downloads/A-large-practice (4).in");
    output.open("/Users/yujianliu/Downloads/sub-1.out");
    int t;
    input >> t;
    for(int i=1;i<=t;i++)
    {
        int R,C;
        input >> R >>C;
        vector<char> row(C,0);
        vector<vector<char> > cake(R,row);
        for(int j=0;j<R;j++)
        {
            for(int k=0; k<C;k++)
                input >> cake[j][k];
        }
        output << "Case #"<< i << ": "<<endl;
        for(int j=0;j<R;j++)
        {
            for(int k=0; k<C;k++)
            {
                if(cake[j][k]!='?')
                {
                    for(int m=j+1;m<R&&cake[m][k]=='?';m++)
                    {
                        cake[m][k]=cake[j][k];
                    }
                    if(j>0&&cake[j-1][k]=='?')
                    {
                        for(int m=0;m<j;m++)
                        {
                            cake[m][k]=cake[j][k];
                        }
                    }
                }
            }
        }
        for(int j=0;j<R;j++)
        {
            for(int k=0;k<C;k++)
            {
                if(cake[j][k]=='?')
                {
                    int m=k;
                    for(;m<C&&cake[j][m]=='?';m++);
                    if(m==C)
                    {
                        for(m=k;m>0&&cake[j][m]=='?';m--);
                        while(k>m)
                        {
                            cake[j][k] = cake[j][m];
                            k--;
                        }
                    }
                    else
                    {
                        while (k<m) {
                            cake[j][k] = cake[j][m];
                            k++;
                        }
                    }
                }
                
            }
            for(int s=0;s<C;s++)
                output<<cake[j][s];
            output<< endl;
        }
    }
    input.close();
    output.close();
}

void Ratarouille_Small()
{
    ifstream input;
    ofstream output;
    input.open("/Users/yujianliu/Downloads/A-small-attempt1.in");
    output.open("/Users/yujianliu/Downloads/sub-1.out");
    int t;
    input >> t;
    for(int i=1;i<=t;i++)
    {
        int N,P;
        input >> N >> P;
        vector<int> ingredients(N,0);
        vector< vector<int> > packages(P,ingredients);
        
        int res=0;
        output << "Case #"<<i<<": ";
        for(int j=0;j<N;j++)
        {
            input >> ingredients[j];
        }
        for(int k=0;k<N;k++)
        {
            for(int j=0;j<P;j++)
            {
                input >> packages[j][k];
            }
        }
        for(int j=0;j<P;j++)
        {
            float maxlb=0;
            float minub=__FLT_MAX__;
            for(int k=0;k<N;k++)
            {
                maxlb=maxlb > packages[j][k]/(ingredients[k]*1.1) ? maxlb : packages[j][k]/(ingredients[k]*1.1);
                minub=minub < packages[j][k]/(ingredients[k]*0.9) ? minub : packages[j][k]/(ingredients[k]*0.9);
            }
            if(maxlb<minub)
                res++;
        }
        output<<res<<endl;
    }
    input.close();
    output.close();
}

void Cruise_Control()
{
    ifstream input;
    ofstream output;
    input.open("/Users/yujianliu/Downloads/A-large (1).in");
    output.open("/Users/yujianliu/Downloads/sub-1.out");
    int t;
    input>>t;
    for(int i=1;i<=t;i++)
    {
        output<<"Case #"<< i<<": ";
        int D,N;
        input>>D>>N;
        double maxtime=0;
        for(int i=0;i<N;i++)
        {
            int dis,sp;
            input >> dis >>sp;
            maxtime= (double)(D-dis)/sp < maxtime ? maxtime : (double)(D-dis)/sp;
        }
        double res = D/maxtime;
        output<<fixed<<setprecision(6);
        output<<  res<<endl;
    }
    input.close();
    output.close();
}
string helper(map<char,int> horses, string current,int size);
void Stable_Neighbors()
{
    ifstream input;
    ofstream output;
    input.open("/Users/yujianliu/Downloads/A-large (1).in");
    output.open("/Users/yujianliu/Downloads/sub-1.out");
    int t;
    input>>t;
    for(int i=1;i<=t;i++)
    {
        int N;
        input>>N;
        map<char,int> horses;
        string res;
        output<<"Case #"<<i<<": ";
        input>>horses['R'];
        input>>horses['O'];
        input>>horses['Y'];
        input>>horses['G'];
        input>>horses['B'];
        input>>horses['V'];
        if(horses['R']+horses['Y']<horses['B']||horses['B']+horses['Y']<horses['R']||horses['R']+horses['B']<horses['Y'])
            res="IMPOSSIBLE";
        else
            res = helper(horses, res, N);
        cout<<res<<endl;
    }
    input.close();
    output.close();
}

string helper(map<char,int> horses, string current,int size)
{
    if(current.size()==size)
    {
        if(current[0]!=current.back())
            return current;
        else
            return "IMPOSSIBLE";
    }
    else
    {
        string test=current;
        for(auto it= horses.begin();it!=horses.end();it++)
        {
            if(it->second!=0&&it->first!=test.back())
            {
                test+=(it->first);
                (it->second)--;
                test = helper(horses, test, size);
                if(test!="IMPOSSIBLE")
                    return test;
                else
                {
                    test = current;
                    (it->second)++;
                }
            }
        }
    }
    return "IMPOSSIBLE";
}




void printList(ListNode* head)
{
    while(head)
    {
        cout << head->val;
        head = head->next;
        if(head)
        {
            cout << "->";
        }
    }
}

vector<int> makeVector()
{
    int myints[] = {15252,16764,27963,7817,26155,20757,3478,22602,20404,6739,16790,10588,16521,6644,20880,15632,27078,25463,20124,15728,30042,16604,17223,4388,23646,32683,23688,12439,30630,3895,7926,22101,32406,21540,31799,3768,26679,21799,23740};
    vector<int> myVec(myints, myints + sizeof(myints) / sizeof(int));
    return myVec;
}


void InOrderTraverse(TreeNode* root)
{
    if(root->left)
    InOrderTraverse(root->left);
    
    cout << root->val;
    
    if(root->right)
        InOrderTraverse(root->right);
}


int minimumDifference = INT_MAX, val = -1;

int getMinimumDifference(TreeNode* root) {
    if(root->left)getMinimumDifference(root->left);
    if(val >= 0)  minimumDifference = min(minimumDifference, root->val - val);
    val = root->val;
    if(root->right)getMinimumDifference(root->right);
    return minimumDifference;
}



double findMaxAverage2(vector<int>& nums, int k) {
    size_t n = nums.size();
    int i = 0;
    double result = 0.0;
    vector< pair<int, int> > dp(n - k + 1, make_pair(0 , 0));
    
    while (i != k) {
        dp[0].first += nums[i++];
        dp[0].second++;
    }
    
    result = (double)dp[0].first / dp[0].second;
    double Sum = dp[0].first;
    while (i != n ) {
        double avg1 = 0.0;
        
        avg1 = (double)(dp[i - k].first + nums[i]) / (dp[i - k].second + 1);
        Sum += (nums[i] - nums[i - k]);
        
        double  avg2 = Sum / k;
        if(avg1 > avg2)
        {
            dp[i - k + 1].first = dp[i - k].first + nums[i];
            dp[i - k + 1].second = dp[i - k].second + 1;
            result = max(result, avg1);
        }
        else
        {
            dp[i - k + 1].first = Sum;
            dp[i - k + 1].second = k;
            result = max(result, avg2);
        }
        ++i;
        
    }
    return result;
}



int main()
{
    /*string word("oath");
    vector< vector<char> > board;
    vector<char> a;
    vector<string> words;
    words.push_back(word);
    words.push_back("pea");
    words.push_back("eat");
    words.push_back("rain");
    for(int j = 0; j < 4; j++)
    {
        
        for(int i = 0; i < 4; i++)
    {
        char x;
        cin >> x;
        a.push_back(x);
    }
        board.push_back(a);
        a.clear();
    }
    // words = findWords(board, words);
    // for(auto word : words)
    //    cout << word << endl;
    char myChar[] = {'A','A','A','A','A','A','B','C','D','E','F','G'};
    vector<char> tasks(myChar, myChar + sizeof(myChar) / sizeof(char));*/
    TreeNode a(1), b(2), c(3), d(4), e(5), f(0), g(4), h(1), i(2);
    a.left = &b;
    a.right = &c;
    b.left = NULL;
    b.right = NULL;
    c.left = NULL;
    c.right = NULL;
    d.left = NULL;
    d.right = &e;
    e.left = NULL;
    e.right = NULL;
    
    /*vector<vector<int>> prerequisites;
    for(int i = 0; i < 15; ++i)
    {
        vector<int> a1;
        for(int j = 0; j < 15; ++j)
        {
            int k;
            cin >> k;
            a1.push_back(k);
        }
        prerequisites.push_back(a1);
    }*/
    
    
    string s("");
    vector<int> m = makeVector();
    vector<vector<int>> mm = {{4,1},{3,5},{5,2},{4,2},{1,3}};
    
   // auto answer = searchRange(m, 8);
    
    
    Interval i1(0,6), i2(9, 16), i3(17, 17);
    vector<Interval> intervals{i1, i2, i3};
        
    
    
    
    Interval newInterval(6, 11);
    
    
    //vector<Interval> result = test(intervals, newInterval);
   
    vector<string> words;
    words.push_back("practice");
    words.push_back("makes");
    words.push_back("perfect");
    words.push_back("coding");
    words.push_back("makes");
    string word1("coding");
    string word2("practice");
    MapSum obj = MapSum();
     obj.insert("apple", 3);
    //cout << obj.sum("ap");
    ListNode l1(5), l2(5);
   
    //cout << maximumGap(m);
    cout<< lengthOfLongestSubstring("pwwkew");
    
    return 0;
}














