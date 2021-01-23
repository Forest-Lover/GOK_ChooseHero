#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <cmath>

using namespace std;

enum JOB {
    J_TOP   = 1,  //上单
    J_JUN   = 2,  //打野
    J_SUP   = 3,  //辅助
    J_MID   = 4,  //中单
    J_ADC   = 5,  //射手
};


struct Hero {
    string _Chinese_name;
    JOB         _job;
    vector<pair<string, float> >    _restrain_list;  //克制列表 pinyin_name
    vector<pair<string, float> >    _berestrain_list;  //被克制列表 pinyin_name

    Hero(){}
    Hero(string Chinese_name, JOB job, vector<pair<string, float> > &&restrain_list, vector<pair<string, float> > &&berestrain_list)
        : _Chinese_name(Chinese_name), _job(job), _restrain_list(restrain_list), _berestrain_list(berestrain_list) {}
};

int main()
{
    //读入英雄列表
    map<string, Hero> hero_map;  //英雄列表 key:pinyin_name
    hero_map["lvbu"]    = Hero("吕布", J_TOP, 
                            vector<pair<string, float> >{make_pair("mengqi", 8.19), make_pair("change", 6.90), make_pair("baiqi", 4.32)}, 
                            vector<pair<string, float> >{make_pair("lixin", 5.40), make_pair("miyue", 5.11), make_pair("yuange", 4.80)}); 
    hero_map["yase"]    = Hero("亚瑟", J_TOP, 
                            vector<pair<string, float> >{make_pair("gongsunli", 6.41), make_pair("buzhihuowu", 5.53), make_pair("machao", 4.07)}, 
                            vector<pair<string, float> >{make_pair("dianwei", 3.02), make_pair("caiwenji", 2.00), make_pair("baiqi", 1.84)}); 
    /*
    hero_map[""] = Hero("", J_TOP, 
                            vector<pair<string, float> >{make_pair("", ), make_pair("", ), make_pair("", )}, 
                            vector<pair<string, float> >{make_pair("", ), make_pair("", ), make_pair("", )}); 
    */

    //初始化配置
    map<pair<string, string>, float> restrain_map;  //英雄克制表 key<A,B>, A克制B vaule为正
    for (auto &kv : hero_map) {
        for (auto &v : kv.second._restrain_list) {
            auto key    = make_pair(kv.first, v.first);
            auto bekey  = make_pair(v.first, kv.first);
            restrain_map[key]   = v.second;
            restrain_map[bekey] = -v.second;
        }
        for (auto &v : kv.second._berestrain_list) {
            auto bekey  = make_pair(kv.first, v.first);
            auto key    = make_pair(v.first, kv.first);
            restrain_map[key]   = v.second;
            restrain_map[bekey] = -v.second;
        }
    }

    //dump
    cout << "-----------dump restrain_map-----------" << endl;
    for (auto &kv : restrain_map) {
        cout << "key:<" << kv.first.first << "," << kv.first.second << ">\tvalue:" << kv.second << endl;
    }
    cout << "restrain_size:" << restrain_map.size() << endl;
    cout << "英雄列表:" << endl;
    int tmp_cnt = 0;
    for (auto &kv : hero_map) {
        cout << kv.second._Chinese_name << "(" << kv.first << ")\t";
        if (++tmp_cnt % 10 == 0)
            cout << endl;
    }
    cout << endl << "hero_size:" << restrain_map.size() << endl;

    //开始选英雄
    cout << "-----------CHOOSE HERO-----------" << endl;
    enum {S_RED = 0, S_BLUE = 1};
    const vector<int> SEQUENCE{1, 0, 0, 1, 1, 0, 0, 1, 1, 0};  //选将顺序 1:蓝方 2:红方
    vector<string> choosed_list;
    for (auto cur_seq : SEQUENCE) {
        struct RestrainInfo {
            vector<float> _val_list;  //对每个英雄的克制值
            float   _total_val      = 0.f;  //总净值
            float   _abs_total_val  = 0.f;  //总绝对值
        };
        map<string, RestrainInfo> restrain_info_map;  //所有英雄克制计算值
        if (choosed_list.empty()) {
            //TODO 默认英雄
            cout << "默认推荐：。。。" << endl;
        } else {
            //calc
            for (auto &kv : hero_map) {
                auto &info = restrain_info_map[kv.first];
                for (auto &v : choosed_list) {
                    auto key = make_pair(kv.first, v);
                    info._val_list.push_back(restrain_map[key]);
                }
                for (size_t idx = 0; idx < info._val_list.size() && idx < SEQUENCE.size(); ++idx) {
                    float val = info._val_list[idx];
                    if (SEQUENCE[idx] == cur_seq) {
                        //alliance
                    } else {
                        //enemy
                        info._total_val += val;
                        info._abs_total_val += fabs(val);
                    }
                }
            }
            //sort
            vector<pair<string, RestrainInfo>> info_list(restrain_info_map.begin(), restrain_info_map.end());
            sort(info_list.begin(), info_list.end(), [](const decltype(info_list)::value_type &l, const decltype(info_list)::value_type &r){
                 return l.second._total_val > r.second._total_val;
                 });
            //inform
            const int RECOMMEND_COUNT = 5;  //推荐数量
            int t_cnt = 0;
            for (auto &kv : info_list) {
                //skip choosed
                auto it = find(choosed_list.begin(), choosed_list.end(), kv.first);
                if (it != choosed_list.end())
                    continue;
                //max show count
                if (++t_cnt > RECOMMEND_COUNT)
                    break;
                auto &info_hero = hero_map[kv.first];
                auto &info_res  = kv.second;
                cout << "<" << t_cnt << ">" << info_hero._Chinese_name << ":\t";
                for (size_t i = 0; i < info_res._val_list.size() && i < choosed_list.size() && i < SEQUENCE.size(); ++i) {
                    //跳过己方
                    if (cur_seq == SEQUENCE[i])
                        continue;
                    cout << choosed_list[i] << ":" << info_res._val_list[i] << ",\t";
                }
                cout << "总克制值:" << info_res._total_val << "\t";
                cout << "绝对值:" << info_res._abs_total_val << "\t";
                cout << endl;
            }
        }
        if (cur_seq == S_BLUE) {
            cout << "<蓝方> 请选择英雄:";
        } else if (cur_seq == S_RED) {
            cout << "<红方> 请选择英雄:";
        }
        string hero_name;
        while (cin >> hero_name) {
            auto it = hero_map.find(hero_name);
            if (it != hero_map.end())
                break;
            cout << "无效值, 请重新输入:";
        }
        choosed_list.push_back(hero_name);
    }
    cout << "Hello world" << endl;
    return 0;
}

