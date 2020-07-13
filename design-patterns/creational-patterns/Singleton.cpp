#include<iostream>
#include<map>
#include<fstream>

class SingletonDatabase {
    std::map<std::string, int32_t>  m_country;
    SingletonDatabase() {
        std::ifstream ifs("country.txt");
        std::string city, population;
        while (getline(ifs, city)) {
            getline(ifs, population);
            m_country[city] = stoi(population);
        }
    }
public:
    SingletonDatabase(SingletonDatabase const &) = delete;
    SingletonDatabase &operator=(SingletonDatabase const &) = delete;
    static SingletonDatabase &get() {
        static SingletonDatabase db;
        return db;
    }
    int32_t get_population(const std::string &name) { std::cout << m_country[name]; }
};
int main() {
    SingletonDatabase::get().get_population("Japan");
    return EXIT_SUCCESS;
}
