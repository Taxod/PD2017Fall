#include <iostream>
#include <stdio.h>

using namespace std;
const int MAX_VILLAGE = 500;

int total_cost = 0;
int total_covered = 0;

void select(int index,
            int village,
            int construct_cost[MAX_VILLAGE],
            int population[MAX_VILLAGE],
            bool selected[MAX_VILLAGE],
            int covered_count[MAX_VILLAGE],
            int satisfied_count[MAX_VILLAGE],
            int **dis)
{
    // cout << "select " << index+1 << endl;
    total_cost += construct_cost[index];
    selected[index] = true;
    
    for (int i = 0; i < village; i++) {
        //距離                   有沒有被滿足               被覆蓋過 
		if (dis[index][i] != 0 && satisfied_count[i] == 0 && covered_count[i] == 0) {
            total_covered++;
        }
        
        if (dis[index][i] == 2) {
            satisfied_count[i]++;
        } else if (dis[index][i] == 1) {
            covered_count[i]++;
        }
    }
}

void remove_select(int index,
                   int village,
                   int construct_cost[MAX_VILLAGE],
                   int population[MAX_VILLAGE],
                   bool selected[MAX_VILLAGE],
                   int covered_count[MAX_VILLAGE],
                   int satisfied_count[MAX_VILLAGE],
                   int **dis)
{
    // cout << "remove select " << index+1 << endl;
    total_cost -= construct_cost[index];
    selected[index] = false;
    for (int i = 0; i < village; i++) {
        if (dis[index][i] == 2) {
            satisfied_count[i]--;
        } else if (dis[index][i] == 1) {
            covered_count[i]--;
        }
    }
}

int find_best_cp(int village,
                 int cost,
                 int construct_cost[MAX_VILLAGE],
                 int population[MAX_VILLAGE],
                 bool selected[MAX_VILLAGE],
                 int covered_count[MAX_VILLAGE],
                 int satisfied_count[MAX_VILLAGE],
                 int **dis)
{
    double best_cp = 0;
    int best_index = -1;
    
    for (int i = 0; i < village; i++) {
        if (selected[i] == true) {
            continue;
        }
        if (total_cost + construct_cost[i] > cost) {
            continue;
        }
        int cover_count = 0;//紀錄i可以cover幾個點
        double current_cp = 0;
        for (int j = 0; j < village; j++) {
            if (dis[i][j] != 0 && satisfied_count[j] == 0 && covered_count[j] == 0) {
                cover_count++;
            }
        }
        current_cp = (double)cover_count / (double)construct_cost[i];
        if (current_cp > best_cp) {
            best_cp = current_cp;
            best_index = i;
        }
    }
    return best_index;
}

//已經覆蓋完以後，在目前還沒有選的城市裡，選一個ＣＰ值最高的城市，然後select他
bool append_select(int village,
                   int cost,
                   int construct_cost[MAX_VILLAGE],
                   int population[MAX_VILLAGE],
                   bool selected[MAX_VILLAGE],
                   int covered_count[MAX_VILLAGE],
                   int satisfied_count[MAX_VILLAGE],
                   int **dis)
{
    double best_satisfy_population_gain_cp = 0;
    int best_index = -1;
    
    for (int i = 0; i < village; i++) {
        //已經選的話就不要選
        if (selected[i]) {
            continue;
        }
        if (total_cost+construct_cost[i] > cost) {
            continue;
        }
        int satisfy_population_gain = 0;
        //再去走過每一個城市（i到其他城市的狀況）
        for (int j = 0; j < village; j++) {
            //j這個城市可以被滿足，且還沒有被任何城市滿足
            if (dis[i][j] == 2 && satisfied_count[j] == 0) {
                satisfy_population_gain += population[j];
            }
        }
        double cp = (double)satisfy_population_gain / construct_cost[i];
        if (cp > best_satisfy_population_gain_cp) {
            best_satisfy_population_gain_cp = cp;
            best_index = i;
        }
    }
    if (best_index != -1) {
        //直接select
        select(best_index, village, construct_cost, population, selected, covered_count, satisfied_count, dis);
        
        //代表我有沒有append
        return true;
    } else {
        //代表我不能再加了，告訴外界就會跳出
        return false;
    }
}
//替換 
bool update_select(int village,
                   int cost,
                   int construct_cost[MAX_VILLAGE],
                   int population[MAX_VILLAGE],
                   bool selected[MAX_VILLAGE],
                   int covered_count[MAX_VILLAGE],
                   int satisfied_count[MAX_VILLAGE],
                   int **dis)
{
    int best_satisfy_population_gain = 0;
    double best_satisfy_population_gain_cp = 0;
    int replace_index = -1;
    int replace_target = -1;
    //i是要替換點 
	for (int i = 0; i < village; i++) {
        if (selected[i]) {
            continue;
        }
        //j是被取代的人 
        for (int j = 0; j < village; j++) {
            if (!selected[j] || i == j) {
                continue;
            }
            //成本超過預算 
            if (total_cost+construct_cost[i]-construct_cost[j] > cost) {
                continue;
            }
            int satisfy_population_gain = 0;
            for (int k = 0; k < village; k++) {
                //只有j覆蓋k，i沒有覆蓋k 
				if (dis[i][k] == 0 && covered_count[k] + satisfied_count[k] == 1 && dis[j][k] != 0) {
                    satisfy_population_gain = 0;
                    break;
                }
                //i可以滿足k，j不滿足k，k沒有被任何東西滿足 
                if (dis[i][k] == 2 && dis[j][k] != 2 && satisfied_count[k] == 0) {
                    satisfy_population_gain += population[k];
                
                } else if (dis[i][k] != 2 && dis[j][k] == 2 && satisfied_count[k] == 1) {
                    satisfy_population_gain -= population[k];
                }
            }
            
            if (satisfy_population_gain <= 0) {
                continue;
            }
            
            int cost_gain = construct_cost[i] - construct_cost[j];
            if (cost_gain <= 0) {
                select(i, village, construct_cost, population, selected, covered_count, satisfied_count, dis);
                remove_select(j, village, construct_cost, population, selected, covered_count, satisfied_count, dis);
                return true;
            }
            double cp = (double)satisfy_population_gain / (double)cost_gain;
            if (cp > best_satisfy_population_gain_cp) {
                best_satisfy_population_gain_cp = cp;
                best_satisfy_population_gain = satisfy_population_gain;
                replace_index = i;
                replace_target = j;
            } else if (cp == best_satisfy_population_gain_cp && satisfy_population_gain > best_satisfy_population_gain) {
                best_satisfy_population_gain_cp = cp;
                best_satisfy_population_gain = satisfy_population_gain;
                replace_index = i;
                replace_target = j;
            }
        }
    }
    if (replace_index != -1 && replace_target != -1) {
        select(replace_index, village, construct_cost, population, selected, covered_count, satisfied_count, dis);
        remove_select(replace_target, village, construct_cost, population, selected, covered_count, satisfied_count, dis);
        return true;
    } else {
        return false;
    }
}

int main()
{
    int village, cost, dis_c = 0, dis_s = 0; // village < 500, cost < 1000
    int population[MAX_VILLAGE] = {0};               // population < 1000
    int construct_cost[MAX_VILLAGE] = {0};           // construct_cost < 1000
    int covered_count[MAX_VILLAGE] = {0};            // 紀錄選了一個點後的覆蓋狀態
    int satisfied_count[MAX_VILLAGE] = {0};          //i這個城鎮被幾個點滿足
    bool selected[MAX_VILLAGE] = {0};
    int cover_by_count[MAX_VILLAGE] = {0};
    int **dis = NULL;
    
    cin >> village >> cost >> dis_c >> dis_s;
    dis = new int*[village];
    for (int i = 0; i < village; ++i)
    {
        dis[i] = new int[village];
    }
    
    for (int i = 0; i < village; ++i)
    {
        cin >> population[i];
    }
    for (int i = 0; i < village; ++i)
    {
        cin >> construct_cost[i];
    }
    for (int i = 0; i < village; ++i)
    {
        dis[i][i] = 0;
        for (int j = i+1; j < village; ++j)
        {
            cin >> dis[i][j];
            if (dis[i][j] == -1) {
                dis[i][j] = 10001;
            }
            dis[j][i] = dis[i][j];
        }
    }
    
    // Floyd-Warshall algorithm to get shortest paths
    for (int k = 0; k < village; k++)
        for (int i = 0; i < village; i++)
            for (int j = 0; j < village; j++)
                if (dis[i][k] + dis[k][j] < dis[i][j])
                    dis[i][j] = dis[i][k] + dis[k][j];

    for (int i = 0; i < village; ++i)
    {
        for (int j = 0; j < village; ++j)
        {
            if (dis[i][j] <= dis_s) {
                dis[i][j] = 2;
                //j 點被覆蓋幾次 
                cover_by_count[j] += 1;
            } else if (dis[i][j] <= dis_c) {
                dis[i][j] = 1;
                cover_by_count[j] += 1;
            } else {
                dis[i][j] = 0;
            }
            // cout << dis[i][j] << " ";
        }
        // cout << endl;
    }
    
    //當只有自己可以被覆蓋時一定要選擇自己
    for (int i = 0; i < village; i++) {
        if (cover_by_count[i] == 1) {
			select(i, village, construct_cost, population, selected, covered_count, satisfied_count, dis);
        }
    }
    //用最高的ＣＰ值（這裏的ＣＰ值是用cover）cover全部的點
    int choice_index = -1;
    while(true) {
        choice_index = find_best_cp(village, cost, construct_cost, population, selected, covered_count, satisfied_count, dis);
        select(choice_index, village, construct_cost, population, selected, covered_count, satisfied_count, dis);
        if (total_covered == village) {
            break;
        }
    }
    
    /////
    
    while (true) {
        bool is_append = false;
        bool changed = false;
        while(true) {
            is_append = append_select(village, cost, construct_cost, population, selected, covered_count, satisfied_count, dis);
            if (is_append == false) {
                break;
            }
            changed = true;
        }
        
        bool is_update = false;
        while(true) {
            is_update = update_select(village, cost, construct_cost, population, selected, covered_count, satisfied_count, dis);
            if (!is_update) {
                break;
            }
            changed = true;
        }
        
        if (!changed) {
            break;
        }
    }
    bool printed = false;
    for (int i = 0; i < village; i++) {
        if (selected[i] == true) {
            if (printed) {
                cout << " ";
            }
            cout << i+1;
            printed = true;
        }
    }
    return 0;
}
