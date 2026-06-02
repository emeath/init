#include <iostream>

class canalMensagem
{
public:
    virtual void enviaMensagem() = 0;

    void teste()
    {
        std::cout << "aaaa\n";
    }
};

class SMS : public canalMensagem
{
public:
    void enviaMensagem() override
    {
        std::cout << "enviando SMS...\n";
    }
    void teste2()
    {
        std::cout << " abc \n";
    }
};

class Whatsapp : public canalMensagem
{
public:
    void enviaMensagem() override
    {
        std::cout << " zap zap ... \n";
    }
};

class GerenciadorNotificacoes
{
    canalMensagem *cm = NULL;

public:
    void setCanalMensagem(canalMensagem *p)
    {
        cm = p;
    }
    void mandaNotificacao()
    {
        cm->enviaMensagem();
    }
};

int main()
{
    // canalMensagem *cm = new SMS();
    // cm->enviaMensagem();
    // cm->teste();
    GerenciadorNotificacoes gn = GerenciadorNotificacoes();
    gn.setCanalMensagem(new SMS());

    gn.mandaNotificacao();

    gn.setCanalMensagem(new Whatsapp());
    gn.mandaNotificacao();

    return 0;
}