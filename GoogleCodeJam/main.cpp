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
    int myints[] = {2933,25237,47306,27137,3341,8281,6912,41438,21941,48579,7638,29790,45942,30034,56363,29652,39595,19131,38709,32190,44535,32539,56120,29810,28338,17702,46034,3855,27978,10062,59458,2669,44064,53082,5802,6806,19348,18829,34524,36455,53867,55170,20420,55339,56060,34040,22670,62733,1463,10521,30424,40922,40863,5107,23080,31681,25394,54481,29585,15505,42385,59414,43304,52319,31878,14732,4417,57503,33558,51564,47310,36123,62050,32713,20639,2302,32502,30112,33923,43070,6668,29852,18167,42838,28344,25405,48477,45329,53715,64325,61498,30119,53209,12060,46897,47978,59357,21083,50049,16076,57664,30949,60184,45967,34086,23998,63491,32592,17556,48014,10521,31073,2803,28673,64642,62206,46436,60858,56658,45826,10912,107,59033,58954,3305,18183,40944,43551,58942,58652,23017,29430,44946,27881,50224,64433,23857,11772,31577,17903,30069,56463,47557,57948,7778,23749,57911,36074,37871,54623,13737,28423,15475,837,37271,57265,36776,19139,55667,14258,1135,34398,4927,55794,48081,44818,50234,23897,4275,38541,4307,31535,38102,46035,44742,48194,49604,22654,29329,31575,43593,4673,59361,55457,22141,37335,14272,40201,13841,54228,52544,21542,61189,8908,29021,20072,53359,45746,15189,30243,23117,44499,42471,29476,20391,62010,48677,42524,34625,829,12402,31743,62306,15960,18874,26560,18757,59494,43205,33475,4359,10738,13076,39541,63126,46348,62545,25981,62483,36467,55394,18575,7187,17666,31883,4900,32275,58655,41264,41787,55289,40838,3,32064,18953,8725,17810,25334,5979,6228,29622,57146,12048,26888,48961,50968,65438,40308,39347,49790,60296,40226,53327,56375,44602,57287,23693,58749,13668,58875,33820,53371,22860,62781,64865,16772,20541,49506,32883,64370,44535,34838,1322,31955,20829,21857,49403,55894,33484,40471,29290,26503,50470,54989,63767,64030,34282,42915,28981,37276,26122,47952,58671,6883,39565,1350,6972,13036,50839,23901,1934,11574,46854,35445,4550,61731,22215,44718,18980,42136,32913,17243,64297,39591,1064,29892,37223,51759,55997,4260,9719,39240,46131,28041,3149,22731,61196,29571,54113,43580,56513,54391,53561,36413,61958,24355,29882,4737,52511,58962,45374,2430,2996,57772,15068,51497,65436,47010,3766,28802,38973,28192,30642,40653,30671,56465,156,49567,53044,17714,57849,59565,11567,25277,28657,60213,1535,35627,53653,31258,58639,57994,45963,21349,35587,2998,25130,39014,22452,9086,57167,13245,40826,60370,2646,18359,21291,43730,52920,60605,23936,9021,51836,34682,30275,41416,59151,64749,25693,7266,3901,62153,48502,61796,3254,5150,5152,321,42107,50379,45006,47826,6408,47489,18749,14097,64425,60190,1314,48397,69,59091,56,41350,55821,58894,38851,55932,55972,21624,32937,55163,35834,45319,1546,46107,13984,24810,43894,23221,39572,33203,30672,6407,24394,25258,45947,14071,13664,33129,22827,43022,33939,3265,58649,29418,47498,21647,10638,5274,25281,60791,21707,40733,4044,7891,46503,19772,39529,50816,13205,61435,28395,40796,8050,29246,19798,38955,893,3632,44996,64776,17178,14020,49321,59730,25420,28565,24223,33803,34764,19775,27666,44380,11393,14464,39778,30175,48424,65204,43964,15703,65302,4743,56311,45344,4545,34242,18627,48678,524,26764,34724,54670,51876,64845,37791,12904,5868,53736,28552,12063,33099,21492,38645,32128,29466,5452,15350,11319,56107,31580,25716,45691,25554,24097,10613,38988,46409,51926,28447,16784,17126,28681,10821,64333,9334,17688,26355,62514,4691,6490,12226,58775,3279,62659,50743,27840,23304,33142,49688,42935,27874,47295,4972,62732,20431,58500,2224,12373,42056,57603,39819,61125,18844,10506,13973,22476,40468,3788,29257,52938,61275,58129,26800,61945,21456,61961,30876,10146,26633,39268,23485,39011,48206,15366,22484,60840,15472,49066,18162,43958,443,61986,43442,43653,39987,44261,19578,50495,48061,55077,50093,29901,54992,28584,29596,38030,36965,58122,49804,51445,37431,51731,24586,5987,37224,57768,54137,47572,3709,50638,1641,18371,62993,4152,42719,22554,49902,61539,64704,65282,53263,37700,13711,16671,53783,14933,13778,6319,24644,27466,64155,50464,61267,36488,49102,8488,22726,13704,56612,41025,3255,22983,59246,53772,31194,38859,41671,36065,32204,42889,19691,47129,7314,55214,25092,40093,11101,26272,13604,3108,45674,23609,62275,3508,5132,5680,31647,41209,65446,36195,49096,45957,7915,28358,58329,8000,16367,55208,56399,51856,56726,15940,26213,54167,43254,22087,43867,60189,10707,2111,34825,12701,2569,56647,47106,34145,49922,4015,63585,21525,47495,34724,43098,12066,55161,43721,56776,35681,58168,44342,16562,27722,49793,3604,22156,54757,6372,29382,37245,364,33284,58011,17588,29728,40077,39560,62879,42477,24125,48626,47087,61608,39196,57322,50161,36038,33805,56509,23471,11561,12103,17978,14019,58516,5360,2998,16203,7348,48124,46800,30407,38948,4047,30789,63444,25711,23055,6218,4150,48419,36936,5981,18204,45399,45539,13517,42091,34233,37703,38199,52906,21893,42608,35578,5184,52287,38027,38473,20498,40264,33908,26752,3519,3018,43799,62618,6722,60057,55487,13166,5538,48417,39525,23750,918,12952,30865,21435,9606,24957,35566,54246,41296,28018,8655,13305,29046,7919,24102,18927,48745,16224,13543,43436,11813,45976,57096,57327,65281,45388,30729,24330,53320,32910,45188,58166,34528,62664,29782,64070,53270,35090,33957,19974,26485,31132,17334,40051,8852,58395,55564,4654,25666,21876,53692,27838,1563,1882,34313,35925,18535,23132,41446,56898,38519,43631,19023,55075,793,6111,23641,63325,37391,33204,59812,23615,16064,53115,2986,15063,26915,10003,35129,53209,52658,38424,23993,19916,47087,41870,32781,23467,14797,8185,2728,48195,28310,22244,64904,44107,36113,54746,46865,59322,53942,30240,59462,42068,41757,41208,47628,61494,24229,48433,54666,7244,48869,34305,52957,49731,54532,26049,24682,34895,10848,13232,49821,26227,20294,55822,7568,14,35508,55809,59085,16328,15440,53698,42963,10781,60408,48528,20393,28196,60905,29450,62023,7063,33821,26021,51520,1947,31510,59946,61914,13225,35257,63813,43294,29529,14147,53308,51836,5798,28031,13820,58126,16026,11353,32727,37204,16554,58158,59942,13752,4139,24909,1022};
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
    TreeNode a(4), b(-7), c(-3), d(-9), e(-3), f(-4), g(4), h(1), i(2);
    a.left = &b;
    a.right = &c;
    b.left = NULL;
    b.right = NULL;
    c.left = &d;
    c.right = &e;
    d.left = NULL;
    d.right = NULL;
    e.left = &f;
    e.right = NULL;
    f.left = NULL;
    f.right = NULL;
    
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
    //cout<<longestUnivaluePath(&a);
    maxSumOfThreeSubarrays(m, 106);
    
    return 0;
}














