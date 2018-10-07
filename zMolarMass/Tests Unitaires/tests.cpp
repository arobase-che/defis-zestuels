#include <cmath>
#include <iostream>
#include <string>

double molar_mass(std::string const & molecule)
{
    // ...
}

// To make double comparison with two decimals.
bool are_same(double a, double b)
{
    // https://stackoverflow.com/a/47906348/6060256
    return std::abs(a - b) < std::pow(10, -2);
}

int main()
{
    std::string const carbon_monoxyde { "CO"s };
    double const carbon_monoxyde_molar_mass { molar_mass(carbon_monoxyde) };
    std::cout << "Molar mass of carbon monoxyde : " << carbon_monoxyde_molar_mass << std::endl;
    assert(are_same(carbon_monoxyde_molar_mass, 28.01));

    std::string const dicarbon_monoxyde { "C2O"s };
    double const dicarbon_monoxyde_molar_mass { molar_mass(dicarbon_monoxyde) };
    std::cout << "Molar mass of dicarbon monoxyde : " << dicarbon_monoxyde_molar_mass << std::endl;
    assert(are_same(dicarbon_monoxyde_molar_mass, 40.02));

    std::string const benzene { "C6H6"s };
    double const benzene_molar_mass { molar_mass(benzene) };
    std::cout << "Molar mass of benzene : " << benzene_molar_mass << std::endl;
    assert(are_same(benzene_molar_mass, 78.11));

    std::string const acetone { "(CH3)2CO"s };
    double const acetone_molar_mass { molar_mass(acetone) };
    std::cout << "Molar mass of acetone : " << acetone_molar_mass << std::endl;
    assert(are_same(acetone_molar_mass, 58.08));

    std::string const dihydroxyacetone { "CO(CH2OH)2"s };
    double const dihydroxyacetone_molar_mass { molar_mass(dihydroxyacetone) };
    std::cout << "Molar mass of dihydroxyacetone : " << dihydroxyacetone_molar_mass << std::endl;
    assert(are_same(dihydroxyacetone_molar_mass, 90.08));

    std::string const citric_acid { "C3H4OH(COOH)3"s };
    double const citric_acid_molar_mass { molar_mass(citric_acid) };
    std::cout << "Molar mass of citric acid : " << citric_acid_molar_mass << std::endl;
    assert(are_same(citric_acid_molar_mass, 192.12));

    std::string const histidine { "NH2CH(C4H5N2)COOH"s };
    double const histidine_molar_mass { molar_mass(histidine) };
    std::cout << "Molar mass of histidine : " << histidine_molar_mass << std::endl;
    assert(are_same(histidine_molar_mass, 155.15));

    std::string const ethidium_bromide { "C21H20BrN3"s };
    double const ethidium_bromide_molar_mass { molar_mass(ethidium_bromide) };
    std::cout << "Molar mass of ethidium bromide : " << ethidium_bromide_molar_mass << std::endl;
    assert(are_same(ethidium_bromide_molar_mass, 394.31));

    std::string const phenacetine { "CH3CONHC6H4OC2H5"s }; 
    double const phenacetine_molar_mass { molar_mass(phenacetine) };
    std::cout << "Molar mass of phenacetine : " << phenacetine_molar_mass << std::endl;
    assert(are_same(phenacetine_molar_mass, 179.22));

    return 0;
}
