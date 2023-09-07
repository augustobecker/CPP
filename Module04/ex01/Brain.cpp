# include "Brain.hpp"

Brain::Brain( void )
{
    srand(time(NULL));
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
    this->ideas[19] = "Go Big or Go home!";
    this->ideas[20] = "A wolf is a wolf; even in a cage, even dressed in silk.";
    this->ideas[21] = "Success is not final, failure is not fatal: It is the courage to continue that counts.";
    this->ideas[22] = "A wolf will never be a pet.";
    this->ideas[23] = "The only thing standing between you and your goal is the story you keep telling yourself as to why you can't achieve it.";
    this->ideas[24] = "I can't change the direction of the wind, but I can adjust my sails to always reach my destination.";
    this->ideas[25] = "Life is short, and it is up to you to make it sweet.";
    this->ideas[26] = "It's a hard-knock life.";
    this->ideas[27] = "In the streets, loyalty is everything.";
    this->ideas[28] = "Keep it real.";
    this->ideas[29] = "The game is cold, but it's fair.";
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
    this->ideas[50] = "The best time to plant a tree was 20 years ago. The second-best time is now.";
    this->ideas[51] = "To be or not to be, that is the question.";
    this->ideas[52] = "The only way to do great work is to love what you do.";
    this->ideas[53] = "Love all, trust a few, do wrong to none.";
    this->ideas[54] = "In the middle of every difficulty lies opportunity.";
    this->ideas[55] = "The only person you should try to be better than is the person you were yesterday.";
    this->ideas[56] = "Life is really simple, but we insist on making it complicated.";
    this->ideas[57] = "The journey of a thousand miles begins with one step.";
    this->ideas[58] = "Your time is limited, don't waste it living someone else's life.";
    this->ideas[59] = "It does not matter how slowly you go as long as you do not stop.";
    this->ideas[60] = "The biggest risk is not taking any risk. In a world that's changing quickly, the only strategy that is guaranteed to fail is not taking risks.";
    this->ideas[61] = "Your value does not decrease based on someone's inability to see your worth.";
    this->ideas[62] = "To be yourself in a world that is constantly trying to make you something else is the greatest accomplishment.";
    this->ideas[63] = "The only limit to our realization of tomorrow will be our doubts of today.";
    this->ideas[64] = "Life is what happens when you're busy making other plans.";
    this->ideas[65] = "The truth is rarely pure and never simple.";
    this->ideas[66] = "I've learned that people will forget what you said, people will forget what you did, but people will never forget how you made them feel.";
    this->ideas[67] = "A golden cage is still a cage.";
    this->ideas[68] = "La beauté plaît aux yeux, la douceur charme l'âme.";
    this->ideas[69] = "I hope you find some peace of mind in this lifetime";
    this->ideas[70] = "Quoth the Raven, 'Nevermore.'";
    this->ideas[71] = "Started from the bottom, now we're here.";
    this->ideas[72] = "I'm on the pursuit of awesomeness, excellence is the bare minimum.";
    this->ideas[73] = "Weak Messages Create Bad Situations.";
    this->ideas[74] = "Qui vivra verra.";
    this->ideas[75] = "Everyday above ground is a great day";
    this->ideas[76] = "If you build it, they will come.";
    this->ideas[77] = "The truth will set you free.";
    this->ideas[78] = "Keep your friends close, but your enemies closer.";
    this->ideas[79] = "They muddy the water, to make it seem deep";
    this->ideas[80] = "Vouloir, c'est pouvoir.";
    this->ideas[81] = "Silence is luxurious.";
    this->ideas[82] = "A wise man once said nothing.";
    this->ideas[83] = "L'espoir fait vivre.";
    this->ideas[84] = "We Repeat What We Don't Repair";
    this->ideas[85] = "Savoir, penser, rêver. Tout est là";
    this->ideas[86] = "All that glitters is not gold.";
    this->ideas[87] = "Tenho em mim todos os sonhos do mundo.";
    this->ideas[88] = "Se todo animal inspira ternura, o que houve, então, com os homens?";
    this->ideas[89] = "If you're going to be weird, be confident about it";
    this->ideas[90] = "I think you should keep going, just to see what happens";
    this->ideas[91] = "Social media seriously harms your mental health";
    this->ideas[92] = "Everything will be okay in the end. If it's not okay, it's not the end";
    this->ideas[93] = "Do good things even if no one cares";
    this->ideas[94] = "You didn't come this far only to come this far";
    this->ideas[95] = "Don't offer a lecture to someone who needs a hug";
    this->ideas[96] = "One day, someone will think about you for the last time in eternity. You will be forgotten by the world and the universe";
    this->ideas[97] = "Though no one can go back and make a brand new start, anyone can start from now and make a brand new ending";
    this->ideas[98] = "Romanticize your life";
    this->ideas[99] = "How you speak to yourself matters";

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
    if (this != &toCopyFrom)
    {
        for (int i = 0; i < 100; i++)
        {
            this->ideas[i] = toCopyFrom.getIdea(i);
        }
    }
    return (*this);
}

std::string Brain::getRandomIdea( void ) const
{
    int random_num;

    random_num = (std::rand() % 100);
    return (this->ideas[random_num]);
}

std::string Brain::getIdea( const int numIdea ) const
{
    if (numIdea < 0 && numIdea >= 100)
        return "";
    return (this->ideas[numIdea]);
}

bool Brain::setIdea( const int numIdea, const std::string newIdea )
{
    if (numIdea < 0 && numIdea >= 100)
        return (false);
    this->ideas[numIdea] = newIdea;
    return (true);
}

void Brain::invertIdeas( void )
{
    std::string temp_idea;
    int i;
    int j;

    i = 0;
    j = 99;
    while (i < j)
    {
        temp_idea = this->ideas[i];
        this->ideas[i] = this->ideas[j];
        this->ideas[j] = temp_idea;
        i++;
        j--;
    }
}

void Brain::displayIdeas( void ) const
{
    for (int i = 0; i < 100; ++i) 
    {
        std::cout << i << ". " << this->ideas[i] << std::endl;
    }
}
