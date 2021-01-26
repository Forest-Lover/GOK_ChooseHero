#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <cmath>

using namespace std;

enum JOB {
    J_INVALID   = 0,  //invalid
    J_TOP       = 1,  //上单
    J_JUN       = 2,  //打野
    J_SUP       = 3,  //辅助
    J_MID       = 4,  //中单
    J_ADC       = 5,  //射手
    J_SIZE
};
const string JOB_STR[J_SIZE] = {
    "invalid_job",
    "上单",
    "打野",
    "辅助",
    "中单",
    "射手",
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
    //-----------中单-------------
    hero_map["anqila"]  = Hero("安琪拉", J_MID, 
                            vector<pair<string, float> >{make_pair("zhongkui", 2.51), make_pair("zhangliang", 2.35), make_pair("liubei", 2.21)}, 
                            vector<pair<string, float> >{make_pair("makeboluo", 3.28), make_pair("yao", 3.23), make_pair("jing", 3.15)}); 
    hero_map["daji"]    = Hero("妲己", J_MID, 
                            vector<pair<string, float> >{make_pair("buzhihuowu", 5.59), make_pair("gongsunli", 5.29), make_pair("machao", 4.94)}, 
                            vector<pair<string, float> >{make_pair("dunshan", 4.47), make_pair("gongbenwuzang", 3.63), make_pair("caiwenji", 3.00)}); 
    hero_map["zhongkui"] = Hero("钟馗", J_MID, 
                            vector<pair<string, float> >{make_pair("dunshan", 6.91), make_pair("huangzhong", 6.02), make_pair("mingshiyin", 3.59)}, 
                            vector<pair<string, float> >{make_pair("aguduo", 5.04), make_pair("zhuangzhou", 4.41), make_pair("direnjie", 3.63)}); 
    hero_map["xiaoqiao"] = Hero("小乔", J_MID, 
                            vector<pair<string, float> >{make_pair("dunshan", 4.00), make_pair("miyue", 3.32), make_pair("gongsunli", 3.07)}, 
                            vector<pair<string, float> >{make_pair("mengtian", 5.66), make_pair("aguduo", 3.42), make_pair("shenmengxi", 3.11)}); 
    hero_map["zhenji"]  = Hero("甄姬", J_MID, 
                            vector<pair<string, float> >{make_pair("aguduo", 7.16), make_pair("yangyuhuan", 4.23), make_pair("caiwenji", 4.07)}, 
                            vector<pair<string, float> >{make_pair("jiangziya", 5.88), make_pair("libai", 5.66), make_pair("nezha", 4.62)}); 
    hero_map["diaochan"] = Hero("貂蝉", J_MID, 
                            vector<pair<string, float> >{make_pair("lanlingwang", 7.53), make_pair("change", 7.49), make_pair("mengtian", 5.94)}, 
                            vector<pair<string, float> >{make_pair("dunshan", 15.01), make_pair("zhangliang", 8.71), make_pair("sikongzhen", 7.07)}); 
    hero_map["zhugeliang"] = Hero("诸葛亮", J_MID, 
                            vector<pair<string, float> >{make_pair("zhuangzhou", 5.25), make_pair("mengtian", 4.27), make_pair("makeboluo", 3.49)}, 
                            vector<pair<string, float> >{make_pair("bianque", 6.84), make_pair("dunshan", 5.70), make_pair("caiwenji", 3.93)}); 
    hero_map["ganjiangmoye"] = Hero("干将莫邪", J_MID, 
                            vector<pair<string, float> >{make_pair("zhuangzhou", 6.31), make_pair("lan", 5.77), make_pair("zhenji", 4.28)}, 
                            vector<pair<string, float> >{make_pair("gongsunli", 6.38), make_pair("guanyu", 5.71), make_pair("machao", 5.07)}); 
    hero_map["wangzhaojun"] = Hero("王昭君", J_MID, 
                            vector<pair<string, float> >{make_pair("dunshan", 12.61), make_pair("gongbenwuzang", 8.54), make_pair("gaojianli", 5.45)}, 
                            vector<pair<string, float> >{make_pair("zhuangzhou", 4.75), make_pair("yuange", 3.67), make_pair("shenmengxi", 3.57)}); 
    hero_map["mozi"]    = Hero("墨子", J_MID, 
                            vector<pair<string, float> >{make_pair("libai", 4.35), make_pair("yixing", 3.13), make_pair("jiangziya", 3.04)}, 
                            vector<pair<string, float> >{make_pair("aguduo", 4.63), make_pair("dunshan", 4.58), make_pair("zhongwuyan", 3.90)}); 
    hero_map["zhangliang"] = Hero("张良", J_MID, 
                            vector<pair<string, float> >{make_pair("diaochan", 8.71), make_pair("dunshan", 7.08), make_pair("gongsunli", 6.19)}, 
                            vector<pair<string, float> >{make_pair("milaidi", 9.83), make_pair("aguduo", 8.64), make_pair("wuzetian", 7.28)}); 
    hero_map["yuange"] = Hero("元歌", J_MID, 
                            vector<pair<string, float> >{make_pair("miyue", 6.49), make_pair("jiangziya", 5.77), make_pair("xishi", 5.40)}, 
                            vector<pair<string, float> >{make_pair("machao", 4.72), make_pair("guanyu", 4.60), make_pair("sikongzhen", 3.77)}); 
    hero_map["milaidi"] = Hero("米莱狄", J_MID, 
                            vector<pair<string, float> >{make_pair("zhangliang", 9.83), make_pair("gongsunli", 7.01), make_pair("makeboluo", 6.74)}, 
                            vector<pair<string, float> >{make_pair("wuzetian", 4.54), make_pair("gaojianli", 4.40), make_pair("shangguanwaner", 4.36)}); 
    hero_map["shangguanwaner"] = Hero("上官婉儿", J_MID, 
                            vector<pair<string, float> >{make_pair("yingzheng", 7.39), make_pair("jiangziya", 6.81), make_pair("zhuangzhou", 5.46)}, 
                            vector<pair<string, float> >{make_pair("gongsunli", 9.78), make_pair("dunshan", 9.74), make_pair("change", 6.08)}); 
    hero_map["buzhihuowu"] = Hero("不知火舞", J_MID, 
                            vector<pair<string, float> >{make_pair("nvwa", 6.60), make_pair("shenmengxi", 5.33), make_pair("shangguanwaner", 5.06)}, 
                            vector<pair<string, float> >{make_pair("milaidi", 6.52), make_pair("change", 5.67), make_pair("daji", 5.59)}); 
    hero_map["yingzheng"] = Hero("嬴政", J_MID, 
                            vector<pair<string, float> >{make_pair("dunshan", 4.07), make_pair("zhuangzhou", 4.06), make_pair("lubanqihao", 3.83)}, 
                            vector<pair<string, float> >{make_pair("mengtian", 10.50), make_pair("machao", 7.62), make_pair("shangguanwaner", 7.39)}); 
    hero_map["gaojianli"] = Hero("高渐离", J_MID, 
                            vector<pair<string, float> >{make_pair("ailin", 5.23), make_pair("lubandashi", 5.07), make_pair("milaidi", 4.40)}, 
                            vector<pair<string, float> >{make_pair("wangzhaojun", 5.45), make_pair("laofuzi", 5.19), make_pair("liyuanfang", 4.24)}); 
    hero_map["simayi"]  = Hero("司马懿", J_MID, 
                            vector<pair<string, float> >{make_pair("ake", 12.55), make_pair("miyue", 5.85), make_pair("jiangziya", 5.47)}, 
                            vector<pair<string, float> >{make_pair("pangu", 8.35), make_pair("change", 6.54), make_pair("yixing", 5.55)}); 
    hero_map["zhouyu"] = Hero("周瑜", J_MID, 
                            vector<pair<string, float> >{make_pair("dunshan", 13.63), make_pair("gongbenwuzang", 7.26), make_pair("aguduo", 4.36)}, 
                            vector<pair<string, float> >{make_pair("jiangziya", 4.24), make_pair("kai", 3.26), make_pair("miyue", 3.16)}); 
    hero_map["bianque"] = Hero("扁鹊", J_MID, 
                            vector<pair<string, float> >{make_pair("zhugeliang", 6.84), make_pair("gongsunli", 5.85), make_pair("change", 5.75)}, 
                            vector<pair<string, float> >{make_pair("miyue", 3.39), make_pair("zhenji", 3.23), make_pair("zhongkui", 3.20)}); 
    hero_map["change"] = Hero("嫦娥", J_MID, 
                            vector<pair<string, float> >{make_pair("shenmengxi", 9.02), make_pair("simayi", 5.54), make_pair("shangguanwaner", 6.08)}, 
                            vector<pair<string, float> >{make_pair("jialuo", 16.39), make_pair("diaochan", 7.49), make_pair("lvbu", 6.90)}); 
    hero_map["wuzetian"] = Hero("武则天", J_MID, 
                            vector<pair<string, float> >{make_pair("zhangliang", 7.28), make_pair("milaidi", 4.54), make_pair("laofuzi", 3.73)}, 
                            vector<pair<string, float> >{make_pair("shenmengxi", 7.46), make_pair("aguduo", 5.71), make_pair("mengqi", 5.64)}); 
    hero_map["shenmengxi"] = Hero("沈梦溪", J_MID, 
                            vector<pair<string, float> >{make_pair("dunshan", 9.72), make_pair("wuzetian", 7.46), make_pair("xishi", 4.74)}, 
                            vector<pair<string, float> >{make_pair("change", 9.02), make_pair("daqiao", 6.58), make_pair("mengqi", 6.26)}); 
    hero_map["nvwa"]    = Hero("女娲", J_MID, 
                            vector<pair<string, float> >{make_pair("baiqi", 3.94), make_pair("yingzheng", 3.50), make_pair("xiangyu", 2.94)}, 
                            vector<pair<string, float> >{make_pair("gongsunli", 8.85), make_pair("ailin", 8.49), make_pair("buzhihuowu", 6.60)}); 
    hero_map["yangyuhuan"] = Hero("杨玉环", J_MID, 
                            vector<pair<string, float> >{make_pair("nezha", 5.62), make_pair("bailixuance", 4.20), make_pair("yingzheng", 4.19)}, 
                            vector<pair<string, float> >{make_pair("aguduo", 7.43), make_pair("houyi", 5.59), make_pair("bianque", 5.40)}); 
    hero_map["xishi"]   = Hero("西施", J_MID, 
                            vector<pair<string, float> >{make_pair("zhangliang", 5.48), make_pair("bailixuance", 4.40), make_pair("niumo", 4.31)}, 
                            vector<pair<string, float> >{make_pair("gongsunli", 6.06), make_pair("lan", 5.92), make_pair("bailishouyue", 5.70)}); 
    hero_map["yixing"]  = Hero("奕星", J_MID, 
                            vector<pair<string, float> >{make_pair("guiguzi", 6.12), make_pair("simayi", 5.55), make_pair("yangyuhuan", 4.01)}, 
                            vector<pair<string, float> >{make_pair("milaidi", 6.06), make_pair("bianque", 5.12), make_pair("huangzhong", 4.01)}); 
    //-----------射手-------------
    hero_map["luban"] 	= Hero("鲁班", J_ADC, 
                            vector<pair<string, float> >{make_pair("dunshan", 8.52), make_pair("aguduo", 4.96), make_pair("taiyizhenren", 3.62)}, 
                            vector<pair<string, float> >{make_pair("yingzheng", 3.83), make_pair("nvwa", 2.88), make_pair("lanlingwang", 2.38)}); 
    hero_map["bailishouyue"] = Hero("百里守约", J_ADC, 
                            vector<pair<string, float> >{make_pair("ake", 6.50), make_pair("xishi", 5.70), make_pair("lanlingwang", 5.56)}, 
                            vector<pair<string, float> >{make_pair("change", 5.17), make_pair("milaidi", 4.87), make_pair("bianque", 3.50)}); 
    hero_map["yuji"] 	= Hero("虞姬", J_ADC, 
                            vector<pair<string, float> >{make_pair("sunwukong", 3.17), make_pair("guanyu", 2.74), make_pair("nakelulu", 2.59)}, 
                            vector<pair<string, float> >{make_pair("aguduo", 3.99), make_pair("lubandashi", 3.67), make_pair("luna", 3.67)}); 
    hero_map["houyi"] 	= Hero("后羿", J_ADC, 
                            vector<pair<string, float> >{make_pair("yangyuhuan", 5.59), make_pair("machao", 4.94), make_pair("peiqinhu", 4.39)}, 
                            vector<pair<string, float> >{make_pair("zhenji", 3.05), make_pair("lanlingwang", 2.99), make_pair("wangzhaojun", 2.34)}); 
    hero_map["jialuo"] 	= Hero("伽罗", J_ADC, 
                            vector<pair<string, float> >{make_pair("change", 16.39), make_pair("yadianna", 6.33), make_pair("liubei", 5.67)}, 
                            vector<pair<string, float> >{make_pair("ake", 6.53), make_pair("lanlingwang", 6.45), make_pair("milaidi", 4.91)}); 
    hero_map["direnjie"] = Hero("狄仁杰", J_ADC, 
                            vector<pair<string, float> >{make_pair("bailixuance", 4.70), make_pair("liyuanfang", 4.45), make_pair("lubandashi", 4.14)}, 
                            vector<pair<string, float> >{make_pair("jialuo", 3.47), make_pair("huangzhong", 2.74), make_pair("mengya", 2.59)}); 
    hero_map["makeboluo"] = Hero("马可波罗", J_ADC, 
                            vector<pair<string, float> >{make_pair("yingzheng", 6.38), make_pair("mengya", 5.46), make_pair("ganjiangmoye", 4.15)}, 
                            vector<pair<string, float> >{make_pair("aguduo", 7.12), make_pair("milaidi", 6.74), make_pair("sikongzhen", 6.06)}); 
    hero_map["sunshangxiang"] = Hero("孙尚香", J_ADC, 
                            vector<pair<string, float> >{make_pair("lvbu", 2.43), make_pair("yingzheng", 2.24), make_pair("nvwa", 2.20)}, 
                            vector<pair<string, float> >{make_pair("dunshan", 4.95), make_pair("milaidi", 2.80), make_pair("sikongzhen", 1.47)}); 
    hero_map["liyuanfang"] = Hero("李元芳", J_ADC, 
                            vector<pair<string, float> >{make_pair("ake", 6.82), make_pair("lanlingwa", 5.84), make_pair("guiguzi", 4.44)}, 
                            vector<pair<string, float> >{make_pair("dunshan", 5.82), make_pair("direnjie", 4.45), make_pair("gongbenwuzang", 4.11)}); 
    hero_map["gongsunli"]  = Hero("公孙离", J_ADC, 
                            vector<pair<string, float> >{make_pair("shangguanwaner", 9.78), make_pair("nvwa", 8.85), make_pair("yingzheng", 6.49)}, 
                            vector<pair<string, float> >{make_pair("milaidi", 7.01), make_pair("yase", 6.41), make_pair("zhangliang", 6.19)}); 
    hero_map["huangzhong"] = Hero("黄忠", J_ADC, 
                            vector<pair<string, float> >{make_pair("dunshan", 7.11), make_pair("zhangliang", 5.23), make_pair("yangyuhuan", 5.16)}, 
                            vector<pair<string, float> >{make_pair("zhongkui", 6.02), make_pair("guiguzi", 3.37), make_pair("makeboluo", 3.26)}); 
    hero_map["mengya"]  = Hero("蒙犽", J_ADC, 
                            vector<pair<string, float> >{make_pair("aguduo", 8.13), make_pair("pangu", 6.52), make_pair("mengtian", 5.79)}, 
                            vector<pair<string, float> >{make_pair("makeboluo", 5.46), make_pair("guanyu", 5.30), make_pair("luna", 4.84)}); 
    hero_map["chengjisihan"] = Hero("成吉思汗", J_ADC, 
                            vector<pair<string, float> >{make_pair("yingzheng", 3.22), make_pair("daqiao", 2.88), make_pair("luna", 2.76)}, 
                            vector<pair<string, float> >{make_pair("lubandashi", 5.26), make_pair("milaidi", 4.43), make_pair("sunce", 4.07)}); 
    hero_map["ailin"]   = Hero("艾琳", J_ADC, 
                            vector<pair<string, float> >{}, 
                            vector<pair<string, float> >{}); 
    //-----------辅助-------------
    hero_map["caiwenji"] = Hero("蔡文姬", J_SUP, 
                            vector<pair<string, float> >{make_pair("zhugeliang", 3.93), make_pair("milaidi", 3.92), make_pair("daji", 3.00)}, 
                            vector<pair<string, float> >{make_pair("dunshan", 8.61), make_pair("guiguzi", 7.14), make_pair("zhenji", 4.07)}); 
    hero_map["yao"]     = Hero("瑶", J_SUP, 
                            vector<pair<string, float> >{make_pair("wuzetian", 5.58), make_pair("nezha", 4.30), make_pair("nvwa", 3.62)}, 
                            vector<pair<string, float> >{make_pair("jialuo", 5.18), make_pair("gongbenwuzang", 4.81), make_pair("dunshan", 4.05)}); 
    hero_map["donghuangtaiyi"] = Hero("东皇太一", J_SUP, 
                            vector<pair<string, float> >{make_pair("dunshan", 4.10), make_pair("lan", 3.15), make_pair("huamulan", 2.90)}, 
                            vector<pair<string, float> >{make_pair("sulie", 3.45), make_pair("bailixuance", 3.14), make_pair("shenmengxi", 2.45)}); 
    hero_map["dunshan"] = Hero("盾山", J_SUP, 
                            vector<pair<string, float> >{make_pair("diaochan", 15.01), make_pair("shangguanwaner", 9.74), make_pair("caiwenji", 8.61)}, 
                            vector<pair<string, float> >{make_pair("zhouyu", 13.63), make_pair("wangzhaojun", 12.61), make_pair("shenmengxi", 9.72)}); 
    hero_map["mingshiyin"] = Hero("明世隐", J_SUP, 
                            vector<pair<string, float> >{make_pair("nezha", 4.17), make_pair("chengjisihan", 3.61), make_pair("zhuangzhou", 3.39)}, 
                            vector<pair<string, float> >{make_pair("mengtian", 4.83), make_pair("lubandashi", 4.68), make_pair("dunshan", 4.24)}); 
    hero_map["zhuangzhou"] = Hero("庄周", J_SUP, 
                            vector<pair<string, float> >{make_pair("sunce", 5.42), make_pair("niumo", 4.77), make_pair("wangzhaojun", 4.75)}, 
                            vector<pair<string, float> >{make_pair("ganjiangmoye", 6.31), make_pair("diaochan", 5.56), make_pair("shangguanwaner", 5.46)}); 
    /*
    hero_map[""] = Hero("", J_SUP, 
                            vector<pair<string, float> >{make_pair("", ), make_pair("", ), make_pair("", )}, 
                            vector<pair<string, float> >{make_pair("", ), make_pair("", ), make_pair("", )}); 
    */

    /*
    //检查配置
    int ret_check = 0; 
    do {
        for (const auto &kv : hero_map) {
            const Hero &hero = kv.second;
            for (auto &v : hero._restrain_list) {
                auto &name = v.first;
                if (hero_map.find(name) == hero_map.end()) {
                    ret_check = 1;
                    cout << hero._Chinese_name << "," << name << endl;
                    break;
                }
            }
            for (auto &v : hero._berestrain_list) {
                auto &name = v.first;
                if (hero_map.find(name) == hero_map.end()) {
                    ret_check = 2;
                    cout << hero._Chinese_name << "," << name << endl;
                    break;
                }
            }
        }
    } while (false);
    if (ret_check != 0) {
        fprintf(stderr, "配置检查失败! ret:%d\n", ret_check);
        exit(1);
    }
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
        stringstream ss_key;
        ss_key << "key:<" << kv.first.first << "," << kv.first.second << ">";
        cout << setiosflags(ios::left) << setw(30) << ss_key.str() << "\tvalue:" << kv.second << endl;
    }
    cout << "restrain_size:" << restrain_map.size() << endl;

    cout << "-----------dump hero map-----------" << endl;
    cout << "英雄列表:" << endl;
    int tmp_cnt[J_SIZE] = {0};
    stringstream ss[J_SIZE];
    for (auto &kv : hero_map) {
        auto &hero = kv.second;
        stringstream tmp_ss;
        tmp_ss << hero._Chinese_name << "(" << kv.first << ")";
        ss[hero._job] << setiosflags(ios::left) << setw(30) << tmp_ss.str() << "\t";
        if (++tmp_cnt[hero._job] % 5 == 0)
            ss[hero._job] << endl;
    }
    for (int i = 1; i < J_SIZE; ++i) {
        cout << "<<" << JOB_STR[i] << ">>(" << tmp_cnt[i] << "):" << endl;
        cout << ss[i].str() << endl << endl;;
    }
    cout << endl << "total hero size:" << hero_map.size() << endl;


    //开始选英雄
    enum SIDE {S_RED = 0, S_BLUE = 1, S_SIZE};
    const string SIDE_STR[S_SIZE] = {
        "红方",
        "蓝方"
    };
    const vector<int> SEQUENCE{1, 0, 0, 1, 1, 0, 0, 1, 1, 0};  //选将顺序 1:蓝方 2:红方
    vector<string> choosed_list;
    for (int i = 0; i <= SEQUENCE.size(); ++i) {
        int cur_side = S_SIZE;  //当前阵营 S_SIZE:观察统计结果
        if (i < SEQUENCE.size())
            cur_side = SEQUENCE[i];
        struct RestrainInfo {
            vector<float> _val_list;  //对每个英雄的克制值
            float   _total_val[S_SIZE]      = {0.f};  //总克制值
            float   _abs_total_val[S_SIZE]  = {0.f};  //总绝对值
            float   _enemy_total_val        = 0.f;  //敌对阵营总克制值
            float   _aliance_total_val      = 0.f;  //友方阵营总克制值
        };
        map<string, RestrainInfo> restrain_info_map;  //所有英雄克制计算值
        cout << "-----------CHOOSE HERO-----------" << endl;
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
                    info._total_val[SEQUENCE[idx]]      += val;
                    info._abs_total_val[SEQUENCE[idx]]  += fabs(val);
                }
                if (cur_side != S_SIZE) {
                    for (int i = 0; i < S_SIZE; ++i) {
                        if (i == cur_side)
                            info._aliance_total_val     += info._total_val[i];
                        else
                            info._enemy_total_val       += info._total_val[i];
                    }
                }
            }
            //已选列表
            cout << "---已选英雄---：" << endl;
            stringstream ss[S_SIZE];
            for (int i = 0; i < choosed_list.size() && i < SEQUENCE.size(); ++i) {
                auto &name = choosed_list[i];
                auto it_res     = restrain_info_map.find(name);
                auto it_hero    = hero_map.find(name); 
                if (it_res == restrain_info_map.end() || it_hero == hero_map.end())
                    continue;
                auto &res_info  = it_res->second; 
                auto &hero_info = it_hero->second;
                stringstream ss_tmp;
                float enemy_total_val = 0.f;  //对敌方总克制值
                for (int side = 0; side < S_SIZE; ++side) {
                    if (side == SEQUENCE[i])
                        continue;
                    enemy_total_val += res_info._total_val[side];
                }
                ss_tmp << hero_info._Chinese_name << "(" << enemy_total_val << ")";
                ss[SEQUENCE[i]] << setiosflags(ios::left) << setw(30) << ss_tmp.str() << "\t";
            }
            for (int i = 0; i < S_SIZE; ++i) {
                cout << "<" << SIDE_STR[i] << ">:" << ss[i].str() << endl;
            }
            //推荐英雄
            if (cur_side != S_SIZE) {
                cout << "---推荐英雄---：" << endl;
                //sort
                vector<pair<string, RestrainInfo>> info_list(restrain_info_map.begin(), restrain_info_map.end());
                sort(info_list.begin(), info_list.end(), [](const decltype(info_list)::value_type &l, const decltype(info_list)::value_type &r){
                    return l.second._enemy_total_val > r.second._enemy_total_val;
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
                        if (cur_side == SEQUENCE[i])
                            continue;
                        cout << choosed_list[i] << ":" << info_res._val_list[i] << ",\t";
                    }
                    cout << "敌方:" << info_res._enemy_total_val << "\t";
                    cout << "友方:" << info_res._aliance_total_val << "\t";
                    cout << endl;
                }
            }
        }

        if (cur_side < S_SIZE)
            cout << "<" << SIDE_STR[cur_side] << "> 请选择英雄：";
        else 
            cout << "英雄选择完毕！" << endl;

        string hero_name;
        while (cin >> hero_name) {
            auto it         = hero_map.find(hero_name);
            auto it_choosed = find(choosed_list.begin(), choosed_list.end(), hero_name);
            if (it != hero_map.end() && it_choosed == choosed_list.end()) {
                //合法英雄 && 未被选择
                break;
            }
            cout << "无效值, 请重新输入:";
        }
        choosed_list.push_back(hero_name);
    }
    cout << "Hello world" << endl;
    return 0;
}

