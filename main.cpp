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
    //-----------上单-------------
    hero_map["lvbu"]    = Hero("吕布", J_TOP, 
                            vector<pair<string, float> >{make_pair("mengqi", 8.19), make_pair("change", 6.90), make_pair("baiqi", 4.32)}, 
                            vector<pair<string, float> >{make_pair("lixin", 5.40), make_pair("miyue", 5.11), make_pair("yuange", 4.80)}); 
    hero_map["yase"]    = Hero("亚瑟", J_TOP, 
                            vector<pair<string, float> >{make_pair("gongsunli", 6.41), make_pair("buzhihuowu", 5.53), make_pair("machao", 4.07)}, 
                            vector<pair<string, float> >{make_pair("dianwei", 3.02), make_pair("caiwenji", 2.00), make_pair("baiqi", 1.84)}); 
    hero_map["kai"]     = Hero("凯", J_TOP, 
                            vector<pair<string, float> >{make_pair("liubei", 5.98), make_pair("miyue", 5.51), make_pair("change", 4.39)}, 
                            vector<pair<string, float> >{make_pair("dunshan", 2.21), make_pair("mengtian", 1.47), make_pair("zhuangzhou", 1.07)}); 
    hero_map["xiahoudun"] = Hero("夏侯惇", J_TOP, 
                            vector<pair<string, float> >{make_pair("laofuzi", 4.25), make_pair("gongsunli", 2.72), make_pair("ailin", 2.67)}, 
                            vector<pair<string, float> >{make_pair("xishi", 3.44), make_pair("lvbu", 2.61), make_pair("nvwa", 2.44)}); 
    hero_map["dianwei"] = Hero("典韦", J_TOP, 
                            vector<pair<string, float> >{make_pair("lan", 4.96), make_pair("gongbenwuzang", 3.65), make_pair("yase", 3.02)}, 
                            vector<pair<string, float> >{make_pair("bailixuance", 6.68), make_pair("libai", 5.52), make_pair("luna", 4.98)}); 
    hero_map["juyoujing"] = Hero("橘右京", J_TOP, 
                            vector<pair<string, float> >{make_pair("liubei", 2.75), make_pair("yingzheng", 2.34), make_pair("yunzhongjun", 2.14)}, 
                            vector<pair<string, float> >{make_pair("aguduo", 3.21), make_pair("sikongzhen", 2.79), make_pair("buzhihuowu", 1.97)}); 
    hero_map["miyue"]   = Hero("芈月", J_TOP, 
                            vector<pair<string, float> >{make_pair("lvbu", 5.11), make_pair("nezha", 4.40), make_pair("dianwei", 4.36)}, 
                            vector<pair<string, float> >{make_pair("yuange", 6.49), make_pair("simayi", 5.85), make_pair("kai", 5.51)}); 
    hero_map["chengyaojin"] = Hero("程咬金", J_TOP, 
                            vector<pair<string, float> >{make_pair("shenmengxi", 3.21), make_pair("gongsunli", 2.95), make_pair("peiqinhu", 2.91)}, 
                            vector<pair<string, float> >{make_pair("diaochan", 4.48), make_pair("bailixuance", 2.67), make_pair("dianwei", 2.51)}); 
    hero_map["lixin"]   = Hero("李信", J_TOP, 
                            vector<pair<string, float> >{make_pair("lvbu", 5.40), make_pair("zhenji", 2.99), make_pair("zhuangzhou", 2.57)}, 
                            vector<pair<string, float> >{make_pair("dunshan", 4.49), make_pair("yangjian", 3.82), make_pair("xialuote", 3.70)}); 
    hero_map["xialuote"] = Hero("夏洛特", J_TOP, 
                            vector<pair<string, float> >{make_pair("lixin", 3.70), make_pair("yuange", 3.09), make_pair("machao", 2.58)}, 
                            vector<pair<string, float> >{make_pair("baiqi", 4.61), make_pair("dianwei", 2.25), make_pair("dunshan", 2.03)}); 
    hero_map["sulie"]   = Hero("苏烈", J_TOP, 
                            vector<pair<string, float> >{make_pair("donghuangtaiyi", 3.45), make_pair("simayi", 3.32), make_pair("mingshiyin", 3.14)}, 
                            vector<pair<string, float> >{make_pair("zhouyu", 4.19), make_pair("miyue", 4.12), make_pair("sikongzhen", 3.85)}); 
    hero_map["xiangyu"] = Hero("项羽", J_TOP, 
                            vector<pair<string, float> >{make_pair("gaojianli", 2.88), make_pair("laofuzi", 2.59), make_pair("dunshan", 2.53)}, 
                            vector<pair<string, float> >{make_pair("miyue", 4.11), make_pair("jiangziya", 3.36), make_pair("nvwa", 2.94)}); 
    hero_map["laofuzi"] = Hero("老夫子", J_TOP, 
                            vector<pair<string, float> >{make_pair("nezha", 6.55), make_pair("gaojianli", 5.19), make_pair("simayi", 4.69)}, 
                            vector<pair<string, float> >{make_pair("pangu", 4.25), make_pair("xiahoudun", 4.25), make_pair("liuchan", 4.07)}); 
    hero_map["sikongzhen"] = Hero("司空震", J_TOP, 
                            vector<pair<string, float> >{make_pair("machao", 7.39), make_pair("diaochan", 7.07), make_pair("jing", 6.06)}, 
                            vector<pair<string, float> >{make_pair("gongbenwuzang", 4.84), make_pair("mengqi", 3.74), make_pair("dunshan", 3.72)}); 
    hero_map["machao"]  = Hero("马超", J_TOP, 
                            vector<pair<string, float> >{make_pair("yingzheng", 7.62), make_pair("nvwa", 5.45), make_pair("ganjiangmoye", 5.07)}, 
                            vector<pair<string, float> >{make_pair("sikongzhen", 7.39), make_pair("change", 5.98), make_pair("gongbenwuzang", 5.52)}); 
    hero_map["huamulan"] = Hero("花木兰", J_TOP, 
                            vector<pair<string, float> >{make_pair("wangzhaojun", 3.26), make_pair("zhenji", 3.04), make_pair("gaojianli", 2.92)}, 
                            vector<pair<string, float> >{make_pair("zhangliang", 5.48), make_pair("caocao", 4.90), make_pair("machao", 3.48)}); 
    hero_map["guanyu"]  = Hero("关羽", J_TOP, 
                            vector<pair<string, float> >{make_pair("yingzheng", 6.37), make_pair("ganjiangmoye", 5.71), make_pair("mengya", 5.30)}, 
                            vector<pair<string, float> >{make_pair("change", 5.61), make_pair("sikongzhen", 4.60), make_pair("yase", 3.79)}); 
    hero_map["kuangtie"] = Hero("狂铁", J_TOP, 
                            vector<pair<string, float> >{make_pair("mengtian", 9.26), make_pair("zhubajie", 3.50), make_pair("simayi", 3.48)}, 
                            vector<pair<string, float> >{make_pair("lvbu", 2.42), make_pair("dianwei", 2.18), make_pair("zhongkui", 1.40)}); 
    hero_map["sunce"]   = Hero("孙策", J_TOP, 
                            vector<pair<string, float> >{make_pair("mingshiyin", 4.08), make_pair("chengjisihan", 4.07), make_pair("bailixuance", 3.49)}, 
                            vector<pair<string, float> >{make_pair("zhuangzhou", 5.42), make_pair("zhubajie", 3.52), make_pair("gaojianli", 2.53)}); 
    hero_map["gongbenwuzang"] = Hero("宫本武藏", J_TOP, 
                            vector<pair<string, float> >{make_pair("machao", 5.52), make_pair("diaochan", 5.33), make_pair("sikongzhen", 4.84)}, 
                            vector<pair<string, float> >{make_pair("wangzhaojun", 8.54), make_pair("zhouyu", 7.26), make_pair("huangzhong", 5.05)}); 
    hero_map["zhubajie"] = Hero("猪八戒", J_TOP, 
                            vector<pair<string, float> >{make_pair("mengtian", 9.03), make_pair("yangjian", 4.77), make_pair("dunshan", 4.14)}, 
                            vector<pair<string, float> >{make_pair("diaochan", 4.62), make_pair("kuangtie", 3.50), make_pair("mengqi", 2.71)}); 
    hero_map["baiqi"]   = Hero("白起", J_TOP, 
                            vector<pair<string, float> >{make_pair("xialuote", 4.61), make_pair("jialuo", 3.59), make_pair("zhangliang", 3.52)}, 
                            vector<pair<string, float> >{make_pair("mengqi", 6.20), make_pair("lvbu", 4.32), make_pair("zhuangzhou", 4.08)}); 
    hero_map["change"]  = Hero("嫦娥", J_TOP, 
                            vector<pair<string, float> >{make_pair("shenmengxi", 9.02), make_pair("simayi", 6.54), make_pair("shangguanwaner", 6.08)}, 
                            vector<pair<string, float> >{make_pair("jialuo", 16.39), make_pair("diaochan", 7.49), make_pair("lvbu", 6.90)}); 
    hero_map["nezha"]   = Hero("哪吒", J_TOP, 
                            vector<pair<string, float> >{make_pair("zhenji", 4.62), make_pair("lanlingwang", 3.84), make_pair("wuzetian", 2.62)}, 
                            vector<pair<string, float> >{make_pair("laofuzi", 6.55), make_pair("mengqi", 6.13), make_pair("peiqinhu", 5.89)}); 
    hero_map["liubang"] = Hero("刘邦", J_TOP, 
                            vector<pair<string, float> >{make_pair("chengjisihan", 3.09), make_pair("yuji", 2.67), make_pair("nezha", 2.49)}, 
                            vector<pair<string, float> >{make_pair("mengqi", 4.77), make_pair("aguduo", 3.89), make_pair("zhouyu", 3.55)}); 
    hero_map["caocao"]  = Hero("曹操", J_TOP, 
                            vector<pair<string, float> >{make_pair("huamulan", 4.90), make_pair("shangguanwaner", 2.14), make_pair("simayi", 2.05)}, 
                            vector<pair<string, float> >{make_pair("miyue", 3.16), make_pair("sikongzhen", 3.09), make_pair("aguduo", 2.98)}); 
    hero_map["mengtian"] = Hero("蒙恬", J_TOP, 
                            vector<pair<string, float> >{make_pair("yingzheng", 10.50), make_pair("xiaoqiao", 5.66), make_pair("yunzhongjun", 5.66)}, 
                            vector<pair<string, float> >{make_pair("kuangtie", 9.26), make_pair("zhubajie", 9.03), make_pair("lan", 8.61)}); 
    hero_map["yangjian"] = Hero("杨戬", J_TOP, 
                            vector<pair<string, float> >{make_pair("lixin", 3.82), make_pair("mengtian", 2.36), make_pair("nvwa", 2.24)}, 
                            vector<pair<string, float> >{make_pair("zhubajie", 4.77), make_pair("laofuzi", 3.78), make_pair("ailin", 3.31)}); 
    hero_map["yadianna"] = Hero("雅典娜", J_TOP, 
                            vector<pair<string, float> >{make_pair("nvwa", 2.08), make_pair("shenmengxi", 1.97), make_pair("jiangziya", 1.84)}, 
                            vector<pair<string, float> >{make_pair("jialuo", 6.33), make_pair("bianque", 3.86), make_pair("change", 3.25)}); 
    hero_map["pangu"]   = Hero("盘古", J_TOP, 
                            vector<pair<string, float> >{make_pair("simayi", 8.35), make_pair("laofuzi", 5.66), make_pair("machao", 4.12)}, 
                            vector<pair<string, float> >{make_pair("mengya", 6.52), make_pair("zhuangzhou", 3.61), make_pair("zhenji", 3.55)}); 
    hero_map["mengqi"]  = Hero("梦奇", J_TOP, 
                            vector<pair<string, float> >{make_pair("mengtian", 6.39), make_pair("shenmengxi", 6.26), make_pair("luna", 6.21)}, 
                            vector<pair<string, float> >{make_pair("lvbu", 8.19), make_pair("milaidi", 3.45), make_pair("laofuzi", 3.10)}); 
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

