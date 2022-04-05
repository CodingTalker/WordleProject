#include "typeLine.h"
//static short a[26];//26个字母表状态,0表示状态未知,-10表示不含,1-5表示精确知道包含位置同时包含其位置信息，-1--5表示不知道位置仅知道含
//typeLine::typeLine():word(""),type(""){
//}
//
//bool typeLine::isfit(const string& t) const
//{
//    int cnt = 0;
//    for (int i = 0; i < WordSize; i++)
//    {
//        if (a[t[i] - 'a'] == -10)//t中有字母是black的
//            return false;
//        else if (a[t[i] - 'a'] < 0) {//t中有字母是yellow的
//            if (-1 * a[t[i] - 'a'] == i + 1) {
//                return false;
//            }
//            else
//                cnt++;
//        }
//        else if (a[t[i] - 'a'] > 0) {//t中有字母是green的
//            if (a[t[i] - 'a'] != i + 1)
//                return false;
//        }
//    }
//    int num = needFound.size();
//    if (cnt != num)
//        return false;
//    string newstr(t);
//    sort(newstr.begin(), newstr.end());
//    int i = 0, j = 0;
//    while (i != WordSize)
//    {
//        if (j == num)
//            break;
//        if (newstr[i] == needFound[j])
//            j++;
//        i++;
//    }
//    return j == num;
//}
//
//bool typeLine::islegal() const
//{
//    for (size_t i = 0; i < WordSize; i++)
//    {
//        if (word[i] > 'z' || word[i] < 'a')
//            return false;
//    }
//    int cnt = 0;
//    for (size_t i = 0; i < WordSize; i++){
//        if (this->type[i] == 'b' || this->type[i] == 'y' || this->type[i] == 'g')
//            cnt++;
//    }
//    return cnt==WordSize;
//}
//
//void typeLine::update()
//{
//    needFound.clear();
//    for (int i = 0; i < WordSize; i++)
//    {
//        if (this->type[i] == 'b')
//            a[word[i] - 'a'] = -10;
//        else if (this->type[i] == 'y') {
//            a[word[i] - 'a'] = -1 * (i + 1);
//            needFound.push_back(word[i]);
//        }
//        else if (this->type[i] == 'g')
//            a[word[i] - 'a'] = i + 1;
//    }
//    sort(needFound.begin(), needFound.end());
//}
//
//void typeLine::clear()
//{
//    memset(a, 0, sizeof(a));
//    word[0] = 0;
//    type[0] = 0;
//    needFound.clear();
//}
typeLine::typeLine() :word(""), type("") {
}

bool typeLine::isfit(const string& t) const
{
    int curP = 0, bufP = 0;
    bool visited[WordSize];
    memset(visited, 0, sizeof(visited));
    while (curP != WordSize)
    {
        int i;
        for (i = 0; i < WordSize; i++)
        {
            if (visited[i])
                continue;
            if (alphabet[curP].sta == 'g') {
                if (t[i] == alphabet[curP].alpha) {
                    if (posIsIn(alphabet[curP].pos, i)) {
                        visited[i] = true;
                        break;
                    }
                    else
                        return false;
                }
                else
                    continue;
            }
            else if (alphabet[curP].sta == 'b' && t[i] == alphabet[curP].alpha)
                return false;
            else if (alphabet[curP].sta == 'y') {
                if (t[i] == alphabet[curP].alpha) {
                    if (posIsIn(alphabet[curP].pos, i))
                        return false;
                    else {
                        visited[i] = true;
                        break;
                    }
                }
                else
                    continue;
            }
        }
        if (i == WordSize && alphabet[curP].sta != 'b')
            return false;
        else
            curP++;
    }
    return true;
}

bool typeLine::islegal() const
{
    for (size_t i = 0; i < WordSize; i++)
    {
        if (word[i] > 'z' || word[i] < 'a')
            return false;
    }
    int cnt = 0;
    for (size_t i = 0; i < WordSize; i++){
        if (this->type[i] == 'b' || this->type[i] == 'y' || this->type[i] == 'g')
            cnt++;
    }
    return cnt == WordSize;
}

bool typeLine::posIsIn(const vector<int>& t, int val) const
{
    for (size_t i = 0; i < t.size(); i++) {
        if (t[i] == val)
            return true;
    }
    return false;
}

void typeLine::update()
{
    alphabet.clear();
    for (int i = 0; i < WordSize; i++)
    {
        alphaSta t;
        t.alpha = word[i];
        t.sta = type[i];
        //t.pos = i;
        t.pos.push_back(i);
        alphabet.push_back(t);
    }
    sort(alphabet.begin(), alphabet.end());
    //for (size_t i = 0; i < alphabet.size(); i++)
    //{
    //    cout << "前:" << endl;
    //    cout << alphabet[i].alpha << " " << alphabet[i].sta << " " << alphabet[i].pos[0] << endl;
    //}
    bool visited[WordSize];
    memset(visited, 0, sizeof(visited));
    for (size_t i = 0; i < WordSize; i++)
    {
        if (visited[i])
            continue;
        if (alphabet[i].sta != 'y')
            continue;
        for (size_t j = i + 1; j < WordSize; j++)
        {
            if (alphabet[i].alpha == alphabet[j].alpha && alphabet[i].sta == alphabet[j].sta)
                alphabet[i].pos.push_back(alphabet[j].pos[0]);
        }
        for (size_t j = i + 1; j < WordSize; j++)
        {
            if (alphabet[i].alpha == alphabet[j].alpha && alphabet[i].sta == alphabet[j].sta) {
                alphabet[j].pos = alphabet[i].pos;
                visited[j] = true;
            }
        }
    }
    //for (size_t i = 0; i < alphabet.size(); i++)
    //{
    //    cout << "后:" << endl;
    //    cout << alphabet[i].alpha << " " << alphabet[i].sta << " ";
    //    for (size_t j = 0; j < alphabet[i].pos.size(); j++)
    //    {
    //        cout << alphabet[i].pos[j] << " ";
    //    }
    //    cout << "\n";
    //}
}

void typeLine::clear()
{
    word[0] = 0;
    type[0] = 0;
    alphabet.clear();
}
