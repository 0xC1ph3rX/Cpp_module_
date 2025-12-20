/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarza <mtarza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 22:01:14 by mtarza            #+#    #+#             */
/*   Updated: 2025/12/18 23:22:54 by mtarza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>
#include <iterator>

#include <iostream>
#include <string>
#include <fstream>

static std::string replace_re(std::string text, const std::string& s1, const std::string& s2)
{
    if (s1.empty())
        return text;

    std::size_t pos = 0;
    while ((pos = text.find(s1, pos)) != std::string::npos)
    {
        text.erase(pos, s1.length());
        text.insert(pos, s2);
        pos += s2.length();
    }
    return text;
}

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>\n";
        return 1;
    }

    const std::string filename = argv[1];
    const std::string s1 = argv[2];
    const std::string s2 = argv[3];

    if (filename.empty())
    {
        std::cerr << "Error: filename must not be empty.\n";
        return 1;
    }
    if (s1.empty())
    {
        std::cerr << "Error: s1 must not be empty.\n";
        return 1;
    }

    std::ifstream input(filename.c_str());
    if (!input)
    {
        std::cerr << "Error: cannot open input file.\n";
        return 1;
    }

    std::ofstream output((filename + ".replace").c_str());
    if (!output)
    {
        std::cerr << "Error: cannot create output file.\n";
        return 1;
    }

    std::string line;
    while (std::getline(input, line))
    {
        output << replace_re(line, s1, s2);

        if (!input.eof())
            output << '\n';
    }

    return 0;
}
