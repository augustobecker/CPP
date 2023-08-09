# include "Brain.hpp"

Brain::Brain( void )
{
    int i;
    this->ideas[0] = "Don't explain your Philosophy. Embody it";
    this->ideas[1] = "Be as you wish to seen";
    this->ideas[2] = "Caution, Rebooting will erase everything in memory";
    this->ideas[3] = "People say a lot. So watch what they do";
    this->ideas[4] = "Only life and death change all things";
    this->ideas[5] = "There are always flowers for those who want to see them";
    this->ideas[6] = "If you can't convince them, confuse them";
    this->ideas[7] = "Choose what's good for your soul, not your ego";
    this->ideas[8] = "Use art to tell a secret";
    this->ideas[9] = "Apparently all the cool guys listen to mgk";
    this->ideas[10] = "Dont rush anything. Good people end up with good people";
    this->ideas[11] = "There is no right time, just time and what you do with it";
    this->ideas[12] = "dicen que al final ganan los que se atreven";
    this->ideas[13] = "Healing also means taking responsibility for the role you play in your own suffering";
    this->ideas[14] = "While you're alive, it's never too late";
    this->ideas[15] = "Breathe. You're going to figure it out, like you always do";
    this->ideas[16] = "Ego is the enemy";
    this->ideas[17] = "Enjoy the space between where you are and where you are going";
    this->ideas[18] = "Look around you. Appreciate what you have. Nothing will be the same in a year.";
    this->ideas[19] = "If you're going to be weird, be confident about it";
    this->ideas[20] = "I think you should keep going, just to see what happens";
    this->ideas[21] = "Social media seriously harms your mental health";
    this->ideas[22] = "Everything will be okay in the end. If it's not okay, it's not the end";
    this->ideas[23] = "Do good things even if no one cares";
    this->ideas[24] = "You didn't come this far only to come this far";
    this->ideas[25] = "Don't offer a lecture to someone who needs a hug";
    this->ideas[26] = "One day, someone will think about you for the last time in eternity. You will be forgotten by the world and the universe";
    this->ideas[27] = "Though no one can go back and make a brand new start, anyone can start from now and make a brand new ending";
    this->ideas[28] = "Romanticize your life";
    this->ideas[29] = "How you speak to yourself matters";
    this->ideas[30] = "Fake it till you make it";
    this->ideas[31] = "Os cientistas dizem que somos feitos de átomos, mas um passarinho me diz que somos feitos de histórias";
    this->ideas[32] = "Be who you needed when you were younger";
    this->ideas[33] = "Los tiempos son duros cuando las cosas no tinen sentido";
    this->ideas[34] = "I'm now becoming my own self-fulfilled prophecy";
    this->ideas[35] = "The eyes, Chico. They never lie";
    this->ideas[36] = "As coisas tangíveis tornam-se insensíveis à palma da mão. Mas as coisas findas muito mais que lindas, essas ficarão";
    this->ideas[37] = "Vivre est un acte égoïste";
    this->ideas[38] = "On ne voit bien qu'avec le coeur. L'essentiel est invisible pour les yeux.";
    this->ideas[39] = "Os outros eu conheci por ocioso acaso. A ti vim encontrar porque era preciso";
    this->ideas[40] = "Nothing kills like a life you didn't live";
    this->ideas[41] = "Comparison destroys personality";
    this->ideas[42] = "You've actually been here before. We just made sure you forgot";
    this->ideas[43] = "There are places you haven't been where you already belong";
    this->ideas[44] = "You're only in trouble if you get caught";
    this->ideas[45] = "Digas lo que digas, eres lo que haces";
    this->ideas[46] = "O diabo desta vida é que entre cem caminhos temos que escolher apenas um, e viver com a nostalgia dos outros noventa e nove";
    this->ideas[47] = "ahora hay que vivir hasta quemarse";
    this->ideas[48] = "Todos esses que aí estão. Atravancando meu caminho, Eles passarão... Eu passarinho!";
    this->ideas[49] = "Todas as grandes coisas são difíceis e raras";
    i = 50;
    while (i < 100)
    {
        this->ideas[i] = this->ideas[i - 50];
        i++;
    }
    std::cout << "Brain Constructor called" << std::endl;
}

Brain::~Brain( void )
{
    std::cout << "Brain Destructor called" << std::endl;
}

Brain::Brain(Brain &obj)
{
    std::cout << "Brain Copy Constructor called" << std::endl;
    *this = obj;
}

Brain& Brain::operator=(Brain &toCopyFrom)
{
    std::cout << "Brain Copy Assign Operator called" << std::endl;
    *this = toCopyFrom;
    return (*this);
}

std::string Brain::getIdea( const int numIdea ) const
{
    if (numIdea >= 0 && numIdea < 100)
        return (this->ideas[numIdea]);
    return ("");
}

bool Brain::setIdea( const int numIdea, const std::string newIdea )
{
    if (numIdea < 0 && numIdea >= 100)
        return (false);
    this->ideas[numIdea] = newIdea;
    return (true);
}
