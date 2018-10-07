#include <algorithm>
#include <cassert>
#include <cctype>
#include <iostream>
#include <limits>
#include <map>
#include <string>

using namespace std::string_literals;

std::map<std::string, double> known_molecules =
{ 
    { "C"s, 12.011 },
    { "O"s, 15.999 },
    { "H"s, 1.0079 },
    { "He"s, 4.0026 },
    { "Li"s, 6.941 },
    { "Cl"s, 35.453 },
    { "Na"s, 22.989 },
    { "Br"s, 79.904 },
    { "N"s, 14.006 }
};

double molar_mass(std::string const & molecule)
{
    double result { 0.0 };
    std::size_t const size = std::size(molecule);

    for (std::size_t i { 0 }; i < size; ++i)
    {
        std::string current_atom;
        double atom_mass { 0.0 };
        std::size_t index { i };

        if (molecule[i] == '(')
        {
            auto begin = std::begin(molecule) + i + 1;
            auto end = std::find(begin, std::end(molecule), ')');
            if (end == std::end(molecule))
            {
                throw std::runtime_error("Missing closing parenthesis.");
            }

            current_atom = { begin, end };
            atom_mass += molar_mass(current_atom);

            // +1 because of ')'.
            i += std::size(current_atom) + 1;
        }
        else if (isupper(molecule[i]))
        {
            current_atom = molecule[i];

            // If next one is uppercase, it's another atom.
            if (i + 1 < size && islower(molecule[i + 1]))
            {
                std::size_t counter { i + 1 };
                while (counter < size && islower(molecule[counter]))
                {
                    current_atom += molecule[counter];
                    ++counter;
                }
                i = counter - 1;
            }

            if (known_molecules.count(current_atom) == 0)
            {
                throw std::runtime_error("Unkown atom "s + current_atom + "."s);
            }
            atom_mass += known_molecules[current_atom];
        }

        // To check for digits now.
        index = i + 1;

        if (index < size && isdigit(molecule[index]))
        {
            std::string digits { molecule[index] };

            // Let's get all the potential digits.
            std::size_t counter { index + 1};
            while (counter < size && isdigit(molecule[counter]))
            {
                digits += molecule[counter];
                ++counter;
            }
            index = counter;

            int const coefficient { std::stoi(digits) };
            atom_mass *= coefficient;
        }

        result += atom_mass;
    }

    return result;
}

// To make double comparison with two decimals.
bool are_same(double a, double b)
{
    // https://stackoverflow.com/a/47906348/6060256
    return std::abs(a - b) < std::pow(10, -2);
}

#define MOLECULE(x) #x << " [" << x << "]"
#define MOLAR_MASS(x) std::cout << "Molar mass of " << MOLECULE(x) << " : " << molar_mass(x) << " g/mol." << std::endl

int main()
{
    try
    {
        std::string const carbon_monoxyde { "CO"s };
        MOLAR_MASS(carbon_monoxyde);
        assert(are_same(molar_mass(carbon_monoxyde), 28.01));

        std::string const dicarbon_monoxyde { "C2O"s };
        MOLAR_MASS(dicarbon_monoxyde);
        assert(are_same(molar_mass(dicarbon_monoxyde), 40.02));

        std::string const benzene { "C6H6"s };
        MOLAR_MASS(benzene);
        assert(are_same(molar_mass(benzene), 78.11));

        std::string const acetone { "(CH3)2CO"s };
        MOLAR_MASS(acetone);
        assert(are_same(molar_mass(acetone), 58.08));

        std::string const dihydroxyacetone { "CO(CH2OH)2"s };
        MOLAR_MASS(dihydroxyacetone);
        assert(are_same(molar_mass(dihydroxyacetone), 90.08));

        std::string const citric_acid { "C3H4OH(COOH)3"s };
        MOLAR_MASS(citric_acid);
        assert(are_same(molar_mass(citric_acid), 192.12));

        std::string const histidine { "NH2CH(C4H5N2)COOH"s };
        MOLAR_MASS(histidine);
        assert(are_same(molar_mass(histidine), 155.15));

        std::string const ethidium_bromide { "C21H20BrN3"s };
        MOLAR_MASS(ethidium_bromide);
        assert(are_same(molar_mass(ethidium_bromide), 394.31));

        std::string const phenacetine { "CH3CONHC6H4OC2H5"s }; 
        MOLAR_MASS(phenacetine);
        assert(are_same(molar_mass(phenacetine), 179.22));
    }
    catch (std::runtime_error const & exception)
    {
        std::cerr << "Exception : " << exception.what() << std::endl;
    }

    return 0;
}
