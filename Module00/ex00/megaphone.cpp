/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarza <mtarza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 22:05:47 by mtarza            #+#    #+#             */
/*   Updated: 2025/12/17 22:06:28 by mtarza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream> 

int main(int argc, char ** argv){
    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else{
        for (int i = 1; i < argc; ++i){
            std::string  word(argv[i]);

            for (unsigned int j = 0; j < word.length(); ++j){
                word[j] = toupper(word[j]);
            }
            std::cout << word;
        }
        std::cout << std::endl;
    }
    return (0);
}
