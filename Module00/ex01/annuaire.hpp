/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   annuaire.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 02:29:38 by acesar-l          #+#    #+#             */
/*   Updated: 2023/01/04 23:30:30 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANNUAIRE_HPP
# define ANNUAIRE_HPP

# include <iostream>
# include <cctype>
# include "PhoneBook.hpp"
# include "Contact.hpp"

enum Field
{ 
    FIRST_NAME, 
    LAST_NAME, 
    NICKNAME, 
    PHONE_NBR, 
    DARK_SECRET
};

enum Command
{ 
    ADD,
    SEARCH,
    EXIT,
    NONE
};

# define BLACK				        "\033[0;30m"
# define RED				        "\033[0;31m"
# define GREEN				        "\033[0;32m"
# define YELLOW				        "\033[1;33m"
# define BLUE			    	    "\033[0;34m"
# define PURPLE				        "\033[0;35m"
# define CYAN				        "\033[0;36m"
# define WHITE				        "\033[1;37m"
# define GREY				        "\033[0;90m"
# define RESET				        "\033[0m"

# define    MAX_CONTACTS                8
# define    MAX_CONTACTS_IN_TENS        1
# define    MAX_WIDE_ANNUAIRE_LIST      10

# define    L_ANNUAIRE_HEADER "\n\n\
db      Cb  .d8b.  d8b   db d8b   db db    db  .d8b.  d888888b d8888b. d88888b \n\
" YELLOW "\
88      `D d8' `8b 888o  88 888o  88 88    88 d8' `8b   `88'   88  `8D 88'   \n\
88       ' 88ooo88 88V8o 88 88V8o 88 88    88 88ooo88    88    88oobY' 88ooooo \
" RESET "\n\
88         88~~~88 88 V8o88 88 V8o88 88    88 88~~~88    88    88`8b   88~~~~~ \n\
88booo.    88   88 88  V888 88  V888 88b  d88 88   88   .88.   88 `88. 88.     \n\
Y88888P    YP   YP VP   V8P VP   V8P ~Y8888P' YP   YP Y888888P 88   YD Y88888P \n\n\
                    " WHITE "A CPP Phone Book Management System " RESET "\n\n"

#endif