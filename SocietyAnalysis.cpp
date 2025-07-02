#include <iostream>
#include <string>
#include <vector>
#include <map>

class SociologyConcept {
protected:
    std::string name;
    std::string description;
    
public:
    SociologyConcept(const std::string& n, const std::string& d) : name(n), description(d) {}
    
    virtual void display() const {
        std::cout << "Concept: " << name << "\nDescription: " << description << "\n\n";
    }
    
    virtual ~SociologyConcept() {}
};

class SocialStructure : public SociologyConcept {
private:
    std::vector<std::string> elements;
    
public:
    SocialStructure(const std::string& n, const std::string& d, const std::vector<std::string>& el)
        : SociologyConcept(n, d), elements(el) {}
    
    void display() const override {
        SociologyConcept::display();
        std::cout << "Key Elements:\n";
        for(const auto& el : elements) {
            std::cout << "- " << el << "\n";
        }
        std::cout << "\n";
    }
};

class SocialTheory : public SociologyConcept {
private:
    std::string theorist;
    int year;
    
public:
    SocialTheory(const std::string& n, const std::string& d, const std::string& t, int y)
        : SociologyConcept(n, d), theorist(t), year(y) {}
    
    void display() const override {
        SociologyConcept::display();
        std::cout << "Theorist: " << theorist << "\nYear: " << year << "\n\n";
    }
};

class SocialInstitution : public SociologyConcept {
private:
    std::map<std::string, std::string> functions;
    
public:
    SocialInstitution(const std::string& n, const std::string& d, const std::map<std::string, std::string>& func)
        : SociologyConcept(n, d), functions(func) {}
    
    void display() const override {
        SociologyConcept::display();
        std::cout << "Functions:\n";
        for(const auto& f : functions) {
            std::cout << f.first << ": " << f.second << "\n";
        }
        std::cout << "\n";
    }
};

class SociologyStudyApp {
private:
    std::vector<SociologyConcept*> concepts;
    
public:
    void addConcept(SociologyConcept* concept) {
        concepts.push_back(concept);
    }
    
    void displayAll() const {
        std::cout << "=== SOCIOLOGY CONCEPTS ===\n\n";
        for(const auto& concept : concepts) {
            concept->display();
        }
    }
    
    ~SociologyStudyApp() {
        for(auto& concept : concepts) {
            delete concept;
        }
    }
};

int main() {
    SociologyStudyApp app;
    
    app.addConcept(new SocialStructure(
        "Social Hierarchy",
        "A system where individuals are ranked according to status or authority",
        {"Status", "Roles", "Social stratification"}
    ));
    
    app.addConcept(new SocialTheory(
        "Conflict Theory",
        "A theory that emphasizes the role of coercion and power in producing social order",
        "Karl Marx",
        1848
    ));
    
    app.addConcept(new SocialInstitution(
        "Family",
        "A socially recognized group joined by kinship, marriage, or adoption",
        {
            {"Socialization", "Teaches cultural norms and values"},
            {"Economic support", "Provides material resources"},
            {"Emotional support", "Provides love and companionship"}
        }
    ));
    
    app.addConcept(new SocialStructure(
        "Social Network",
        "A social structure made up of individuals connected by various interdependencies",
        {"Nodes", "Ties", "Groups"}
    ));
    
    app.addConcept(new SocialTheory(
        "Symbolic Interactionism",
        "A framework focusing on how individuals interpret symbols and meanings in interactions",
        "George Herbert Mead",
        1934
    ));
    
    app.displayAll();
    
    return 0;
}
