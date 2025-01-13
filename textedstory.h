#ifndef TEXTEDSTORY_H
#define TEXTEDSTORY_H
#include<QObject>
namespace  {
class textedStory : public QObject
{
    Q_OBJECT
public:
    textedStory() {}
    virtual ~textedStory() {}

    static QStringList prologText;
    static QString getPrologText(int row){
        return prologText.at(row);
    }

    static QStringList teaWalkText;
    static QString getTeaWalkText(int row){
        return teaWalkText.at(row);
    }
};

QStringList textedStory::prologText=QStringList({"Однажды Polly по травке на поле гуляла",
                                        "Одна она кажется очень устала",
                                        "Друзей она долго для совместной прогулки искала",
                                        "Но нигде не могла их найти",
                                        "",
                                        "Когда шел дождь Polly под навесом гуляла",
                                        "Когда пекло солнце Polly с зонтиком отдыхала",
                                        "На своей пасеке Polly мед собирала",
                                        "На рынке около дома Polly мед продавала",
                                        "",
                                        "Долго наша Polly ходила-бродила",
                                        "Пока однажды на улице нового друга нашла.",
                                        "Знакомтесь! Это Lolly - друг очень хороший,\n который есть у нашей Polly!"});

QStringList textedStory::teaWalkText=QStringList({"Polly и Lolly на поле гуляли",
                                                 "Polly и Lolly развлечений искали",
                                                 "На поле этом Polly и Molly \nмонетку нашли",
                                                 "Polly и Lolly в кафе чай \nпить пошли",
                                                 "",
                                                 "Когда Polly и Lolly к \nкафе пришли",
                                                 "Они еще монетку нашли",
                                                 "",
                                                 "У жирафа они чай заказали",
                                                 "Одну монетку жирафу отдали",
                                                 "",
                                                 "Когда чай принесли",
                                                 "К окну Polly и Lolly чай \nпить пошли",
                                                 "Чай допивали",
                                                 "Второй чай заказали",
                                                 "",
                                                 "Когда весь чай в кафе \nповыпивали",
                                                 "Polly и Lolly домой поскакали",
                                                 "",
                                                 "Ведь их дома уже ждали!"});
}
#endif // TEXTEDSTORY_H
