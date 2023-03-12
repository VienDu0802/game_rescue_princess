#include "knight.h"
//chuyen chuoi ve chuoi ky tu thuong
void doiKytuThuong(string &a)
{
    int leng = a.size();
    for(int i =0 ; i < leng ; i++)
    {
        if(a[i]>64 && a[i]<91)
        {
            a[i] = a[i] + 32;
        }
    }
}

///check chuoi merlin
int checkMerlin(string s1)
{
    int length = s1.size();
    for(int i = 0; i < length; i++)
    {
        if(length-i < 6) return 0;
        if(( s1[i]=='m' || s1[i]=='M' )&&s1[i+1]=='e'&&s1[i+2]=='r'&&s1[i+3]=='l'&&s1[i+4]=='i'&&s1[i+5]=='n')
        {
            return 1;
        }
    }
    return 0;
}
/// chuyen ve merlin 
int chuyenMerlin (string s){
    for(int i=0; i < s.size(); i++){
        if(s[i] == 'm'){
            s[i] = s[0];
            s[0] = 'm'; 
        }
        if(s[i] == 'e'){
            s[i] = s[1];
            s[1] = 'e'; 
        }
        if(s[i] == 'r'){
            s[i] = s[2];
            s[2] = 'r'; 
        }
        if(s[i] == 'l'){
            s[i] = s[3];
            s[3] = 'l'; 
        }
        if(s[i] == 'i'){
            s[i] = s[4];
            s[4] = 'i'; 
        }
        if(s[i] == 'n'){
            s[i] = s[5];
            s[5] = 'n'; 
        }
    }

    if(checkMerlin(s)) return 1;
    else return 0;
}


//check remedy, maidenkiss, phoenixdown, recuse
void check(int& value){
    if (value < 0) value = 0 ;
    if( value > 99) value = 99 ;
}

//check HP
void checkHP(int& value){
    if (value < 0) value = 0 ;
    if( value > 999) value = 99 ;
}

//check level
void check_Level(int& value){
    if (value < 0) value = 0 ;
    if( value > 10) value = 10 ;
}

//levelO
int find_levelO(int i) {
	int b,c;
	b = i % 10;
	c = i > 6 ? (b > 5 ? b : 5) : b;
	return c;
}

//prime number
bool PrimeNumber(int a){
    int count = 0;
    for(int m = 1; m <= a ; m++)
    {
       if( a%m == 0) count++;
    }
    if(count==2) return 1;
    else return 0;
}

int check_Nto(int n){
    for(int i=2; i< n; i++)
        if(n%i == 0) return 0;
        return n > 1 ;
}

int check_fibo(int n){
    int fn2 = 0, fn1 = 1, fn;
    if (n == 0)
        return fn2;
    else if (n == 1)
        return fn1;
    else {
        for (int i = 2; i <= n; i++) {
            fn = fn1 + fn2;
            fn2 = fn1;
            fn1 = fn;
        }
        return fn;
    }
}

void checkdinh( int *arr, int nPhantu, int &mtx, int& mti){
    int flag = -1 ; // xet canh len
    int max = -1e9 ;
    for(int i = 0; i < nPhantu; i ++){
        if(arr[i] > max && flag == -1){
            max = arr[i];
            mti = i ;
        }
        else {
            flag=0;
            if(i == nPhantu-1) break ;
            if(arr[i] < arr[i+1]){
                mti = -3;
                break;
            }
        }
    }

    if(mti == -3) mtx = -2;
    else mtx = max ;
}

int abs(int n){
    return n<0 ? -n : n ;
}


void display(int HP, int level, int remedy, int maidenkiss, int phoenixdown, int rescue) {
    cout << "HP=" << HP
        << ", level=" << level
        << ", remedy=" << remedy
        << ", maidenkiss=" << maidenkiss
        << ", phoenixdown=" << phoenixdown
        << ", rescue=" << rescue << endl;
}

void adventureToKoopa(string file_input, int & HP, int & level, int & remedy, int & maidenkiss, int & phoenixdown, int & rescue) {

    //khai bao bien
    rescue = -1;
    int maxHP, temp_level, levelO, count_tihon = 0, count_ech = 0, flag_tihon=-1, flag_ech=-1;
    int event[5], asclepius=0;
    int trangthai = 0; // 0: nguoi, -1: ti hon , 1: ech
    int lancelot = 0 ;
    string file1, file2, file3;
    int nEvent = 0 ;

    //read file
    ifstream input_file(file_input);
    if (input_file.is_open()) {
    
    // read first line to get values of HP, level, remedy, maidenkiss, phoenixdown, rescue
    string line;
    getline(input_file, line);
    istringstream iss(line);
    iss >> HP >> level >> remedy >> maidenkiss >> phoenixdown;
    checkHP(HP); check(remedy); check(maidenkiss); check(phoenixdown);
    check_Level(level);
    

    //maxHP
    maxHP = HP ;


    // read second line (events)
    getline(input_file, line);
    istringstream iss2(line);
    while(iss2 >> event[nEvent]){
        nEvent++;
    }

    // read third line (files)
    getline(input_file, line);
    istringstream iss3(line);
    getline(iss3, file1, ',');
    getline(iss3, file2, ',');
    getline(iss3, file3);

    input_file.close();

    // vua arthur
    if(maxHP == 999) {
        rescue = 1;
        display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
        return;
    }

    //lancelot
    if(check_Nto(HP)){
        lancelot = 1;    
    }

    }
    else {
        cout << "Unable to open file: " << file_input << endl;
    }
    //////////////////////////////////////////////////////////////////////////
    for(int i = 0; i<= nEvent; i++){
        int theEvent = event[i];
        levelO = find_levelO(i+1) ;
        //cout << "levelO -------------  " << levelO <<endl;
        if(HP <= 0){
            if(phoenixdown <= 0) {
                rescue = 0;
                break;
            }
            else {
                phoenixdown--;
                HP = maxHP;
            }
        }

        if(trangthai != 0) {
            count_tihon++;
            if(count_tihon == 4){
                count_tihon = 0;
                if(trangthai == -1) // ti hon
                {
                    HP = HP*5;
                    if(HP > maxHP) HP = maxHP;
                    trangthai = 0;
                }
                if(trangthai == 1) // ech
                {
                    level = temp_level;
                }
            }
        }

        if(i == nEvent){
            rescue = 1;
            break;
        }

        if(i!=0) 
        {
            display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
        }

        //event = 0 
        if(theEvent == 0) {
            rescue = 1 ; 
            display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
            return; //thoat ham ngay lap tuc
        }
        
        //event 1--> 5
            if(theEvent >= 1 && theEvent <= 5){
                //levelO = find_levelO(i+1) ;
                //cout << "levelO -------------  " << levelO <<endl;
                if(level > levelO) {
                    level = level + 1 ;
                    check_Level(level) ;
                }
            
                if(level < levelO) {
                    float damage, bdamage ; 
                    if(theEvent == 1) bdamage = 1 ;
                    if(theEvent == 2) bdamage = 1.5 ;
                    if(theEvent == 3) bdamage = 4.5 ;
                    if(theEvent == 4) bdamage = 7.5 ;
                    if(theEvent == 5) bdamage = 9.5 ;
                    damage = bdamage * levelO * 10 ;
                    HP = HP - damage;  
                    //cout << "theEvent "<< theEvent << " " <<"bdamage " << bdamage << " HP "<< HP <<endl;
                }
            }
            
        if(theEvent == 6) {
            if(trangthai != 0) continue ;
            else if(level == levelO) continue;
            else if (level < levelO){                    
                    trangthai = -1;
                    if(HP<5) HP = 1;
                    else HP = HP/5;

                    if(remedy > 0){
                        remedy--;
                        HP *= 5 ;
                        trangthai = 0;
                        continue;
                    }
            }
            else{
                if(level > levelO) {
                    level = level + 2 ;
                    check_Level(level) ;
                }
            }
        }

        if(theEvent == 7){
            if(trangthai != 0) continue ;
            else if(level == levelO) continue;
            else if (level < levelO){
                temp_level = level;
                level = 1;
                if(maidenkiss >= 1){
                    maidenkiss--;
                    level = temp_level;
                    continue;
                }
            }
            else{
                level = level + 2 ;
                check_Level(level) ;                
            }
        }

        if(theEvent == 11) {
            int n1 = ((level + phoenixdown) % 5 + 1)*3 ;
            int s1 = 0, le_max = 99 ;
            for(int i = 0; i< n1; i++){
                s1 += le_max;
                le_max -= 2;
            }
            HP = HP + (s1 % 100);
            while (check_Nto(HP) == 0)  // tang len so NT gan nhat
            {
                HP++;
            }
            if(HP > maxHP) HP = maxHP ; 
        }

        if(theEvent == 12) {
            if( HP == 1) continue;
            if( HP > 1) {
                for(int i = 2; i < 20; i++ ){
                    if(check_fibo(i) >= HP){
                        HP = check_fibo(i-1);
                        break;
                    }
                }
            }
        }

        if(theEvent > 130) {
            int nPhantudayso ; 
            int *dayso;               
            ifstream input_file(file1);
            if(input_file.is_open()){
                string line1;
                // read first line to get values of HP, level, remedy, maidenkiss, phoenixdown, rescue
                getline(input_file, line1);
                istringstream iss4(line1);
                iss4 >> nPhantudayso ;
                dayso = new int[nPhantudayso];
                getline(input_file, line1);
                
                istringstream iss5(line1);
                int i=0;
                while(getline(iss5, line1, ','))
                {
                    dayso[i] = stoi(line1);
                    i++ ;
                }

            }
            else cout << "khong doc duoc" << endl;
            int n_nam = 0, tmp = theEvent;
            while(tmp != 13){
                n_nam++;
                tmp/=10;
            }
            int nam[n_nam];
            // dem so luong nam va ttu
            for(int i = n_nam-1; i >= 0; i--){
                nam[i] = theEvent%10 ;
                theEvent = theEvent/10 ;
            }
            
            for(int i = 0; i < n_nam; i++){
                if(HP <= 0)
                {
                    if(phoenixdown>0)
                    {
                        phoenixdown--;
                        HP = maxHP;
                    }
                    else break;
                }
                if(nam[i] == 1) {
                    int maxi, mini ;
                    int max = -1e9 , min = 1e9 ;
                    for(int j = nPhantudayso-1; j >= 0; j--){
                        if(dayso[j] > max){
                            max = dayso[j];
                            maxi = j ;
                        }
                        if(dayso[j] < min){
                            min = dayso[j];
                            mini = j ;
                        }
                    }
                    HP = HP - (maxi + mini);
                    if(HP > maxHP) HP = maxHP ;
                }
                if(nam[i] == 2){
                    int mtx, mti;
                    checkdinh(dayso, nPhantudayso, mtx, mti);
                    HP = HP - (mtx + mti) ;
                    if(HP > maxHP) HP = maxHP ;
                }
                if(nam[i] == 3){
                    int maxi2 , mini2;
                    int max = -1e9 , min = 1e9 ;
                    for(int i=0; i < nPhantudayso; i++){
                        if((int)((17*abs(dayso[i])+9)%257) > max) {
                            max = (int)((17*abs(dayso[i])+9)%257) ;
                            maxi2 = i; 
                        }
                        if((int)((17*abs(dayso[i])+9)%257) < min) {
                            min = (int)((17*abs(dayso[i])+9)%257) ;
                            mini2 = i; 
                        }
                    }
                    HP = HP - (maxi2 + mini2) ;
                    if(HP > maxHP) HP = maxHP ;
                }
                if(nam[i]==4)
                {
                    int max = -1e9, max2_3x = -1e9, max2_3i;
                    if(nPhantudayso==1){
                        max2_3x = -5;
                        max2_3i = -7;
                    }
                    else if(nPhantudayso==2)
                    {
                        if((int)((17*abs(dayso[0])+9)%257)>((int)(17*abs(dayso[1])+9)%257))
                        {
                            max2_3x = (int)((17*abs(dayso[1])+9)%257);
                            max2_3i = 1;
                        }
                        else if((int)((17*abs(dayso[0])+9)%257)<((int)(17*abs(dayso[1])+9)%257))
                        {
                            max2_3x = (int)((17*abs(dayso[0])+9)%257);
                            max2_3i = 1;
                        }
                        else {
                            max2_3x = -5;
                            max2_3i = -7;
                        }
                    }
                    else{
                        int max = -1e9;
                        for(int i = 0; i < 3; i++)
                            if((int)((17*abs(dayso[i])+9)%257) > max) max = (int)((17*abs(dayso[i])+9)%257);
                        for(int i = 0; i < 3; i++){
                            if((int)((17*abs(dayso[i])+9)%257)==max)
                                continue;
                            if((int)((17*abs(dayso[i])+9)%257)>max2_3x){
                                max2_3x = (int)((17*abs(dayso[i])+9)%257);
                                max2_3i = i;
                            }
                        }
                            
                    }   
                    HP = HP - (max2_3x + max2_3i);
                    if(HP > maxHP) HP = maxHP;
                }
            }
        }
        if(theEvent== 15) {    
            remedy++;
            check(remedy);
        }
        if (theEvent ==16){
            maidenkiss++;
            check(maidenkiss);
        }
        if (theEvent == 17){
            phoenixdown++;
            check(phoenixdown);
        }
        if(theEvent == 19)
        {
            if(asclepius == 1) continue;
            int sd, sc, **mangThuoc;
            
            ifstream intputfile(file2);
            if(intputfile.is_open())
            {
                string line2;
                getline(intputfile, line2);
                istringstream iss(line2);
                iss >> sd;
                getline(intputfile, line2);
                istringstream iss2(line2);
                iss2 >> sc;
                mangThuoc = new int*[sd];

                for(int i = 0; i < sd; i++){
                    mangThuoc[i] = new int[sc];
                }

                getline(intputfile, line2, '_');
                istringstream iss3(line2);
                for(int i = 0; i < sd; i++)
                {
                    for(int j = 0; j < sc; j++)
                    {
                        iss3 >> mangThuoc[i][j];
                    }
                }
            }
            else cout <<"khong doc duoc";
            int dem = 0;
            for(int i = 0; i < sd; i++)
            {
                for(int j = 0; j < sc; j++)
                {
                    if(dem==3) break;
                    if(mangThuoc[i][j]== 16 || mangThuoc[i][j]== 17 || mangThuoc[i][j]== 18) 
                    {
                        dem++;
                        if(mangThuoc[i][j]==16)
                        {
                            remedy++;
                            if(remedy>99) remedy = 99;
                        }
                        else if(mangThuoc[i][j]==17)
                        {
                            maidenkiss++;
                            if(maidenkiss>99) maidenkiss = 99;
                        }
                        else 
                        {
                            phoenixdown++;
                            if(phoenixdown>99) phoenixdown = 99;
                        }
                    }
                }
                dem = 0;
            }
            asclepius = 1;//dieu kien gap thay thuoc mot lan 
        }
        if(theEvent == 99) 
        {
            if(lancelot == 1 && level >= 8){
                level = 10;
            }
            else if (lancelot == 1 && level < 8){
                rescue = 0;
                display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                return;
            }
            else if (level == 10) {
                continue;
            }
            else {
                rescue = 0 ;
                display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                return;
            }
        }

        if(theEvent == 18)
        {
            int n9;
            string checkAscle;
            ifstream intput_file(file3);
            if(intput_file.is_open())
            {
                string line3;
                getline(intput_file, line3);
                istringstream iss(line3);
                iss >> n9;
                for(int i = 0; i < n9; i++)
                {
                    getline(intput_file, checkAscle);
                    if(checkMerlin(checkAscle))
                    {
                        HP+=3;
                        if(HP > maxHP) HP = maxHP;
                    }
                    else 
                    {
                        doiKytuThuong(checkAscle);
                        if(chuyenMerlin(checkAscle)){
                            HP+=2;
                            if(HP > maxHP) HP = maxHP;
                        }
                    }
                }
            }
            else cout << "khong doc duoc file ";
        }
        //display(HP, level, remedy, maidenkiss, phoenixdown, rescue);    
    }
    //cout << "-----------------------final --------------------------" << endl;
    display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
}
