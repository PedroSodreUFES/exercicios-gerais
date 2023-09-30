#include "eleicao.h"

tEleicao InicializaEleicao()
{
    tEleicao eleicao;
    tCandidato candidato;
    int Candidatos, i=0, j=0, k=0;
    eleicao.votosBrancosGovernador=0;
    eleicao.votosBrancosPresidente=0;
    eleicao.votosNulosGovernador=0;
    eleicao.votosNulosPresidente=0;
    scanf("%d%*c", &Candidatos);
    for(i=0; i<Candidatos; i++)
    {
        candidato = LeCandidato();
        if(ObtemCargo(candidato)=='P')
        {
            eleicao.presidentes[j]= candidato;
            j++;
        }
        else if(ObtemCargo(candidato)=='G')
        {
            eleicao.governadores[k] = candidato;
            k++;
        }
    }
    eleicao.totalGovernadores = k;
    eleicao.totalPresidentes = j;
    return eleicao;
}

tEleicao RealizaEleicao(tEleicao eleicao)
{
    int i=0;
    tEleitor eleitor;
    scanf("%d", &eleicao.totalEleitores);
    for(i=0 ; i<eleicao.totalEleitores ; i++)
    {
        eleitor = LeEleitor();
        eleicao.eleitores[i] = eleitor;
    }
    return eleicao;
}

void ImprimeResultadoEleicao(tEleicao eleicao)
{
    int i=0, j=0;
    
    //mais eleitores que o maximo
    if(eleicao.totalEleitores>MAX_ELEITORES)
    {
        printf("ELEICAO ANULADA\n");
        return;
    }

    //mais de 3 candidatos em algum cargo
    if(eleicao.totalGovernadores>MAX_CANDIDATOS_POR_CARGO||eleicao.totalPresidentes>MAX_CANDIDATOS_POR_CARGO)
    {
        printf("ELEICAO ANULADA\n");
        return;
    }

    //CHECAR SE ALGUM ELEITOR VOTOU DUAS VEZES:
    for(i=0; i<eleicao.totalEleitores ; i++)
    {
        for(j=i+1 ; j<eleicao.totalEleitores ; j++)
        {
            if(EhMesmoEleitor(eleicao.eleitores[i], eleicao.eleitores[j]))
            {
                printf("ELEICAO ANULADA\n");
                return;
            }
        }
    }

    //A VOTACAO
    tCandidato PMaisVotado, GMaisVotado;
    int votou=0, maisvotos=-1, empate=0;
    for(i=0 ; i<eleicao.totalEleitores; i++)
    {
        votou=0;
        //votacao para governador
        if(eleicao.eleitores[i].votoG==0)
        {
            eleicao.votosBrancosGovernador++;
            votou=1;
        }
        else
        {
            for(j=0; j<eleicao.totalGovernadores ; j++)
            {
                if(VerificaIdCandidato(eleicao.governadores[j], eleicao.eleitores[i].votoG))
                {
                    eleicao.governadores[j] = IncrementaVotoCandidato(eleicao.governadores[j]);
                    votou=1;
                }
            }
        }
        if(votou==0)
        {
            eleicao.votosNulosGovernador++;
        }

        //votacao para presidente
        votou=0;
        if(eleicao.eleitores[i].votoP==0)
        {
            eleicao.votosBrancosPresidente++;
            votou=1;
        }
        else
        {
            for(j=0; j<eleicao.totalPresidentes ; j++)
            {
                if(VerificaIdCandidato(eleicao.presidentes[j], eleicao.eleitores[i].votoP))
                {
                    eleicao.presidentes[j] = IncrementaVotoCandidato(eleicao.presidentes[j]);
                    votou=1;
                }
            }
        }
        if(votou==0)
        {
            eleicao.votosNulosPresidente++;
        }
    }

    
    //eleicao presidente
    for(i=0; i<eleicao.totalPresidentes ; i++)
    {
        if(eleicao.presidentes[i].votos>maisvotos)
        {
            maisvotos=eleicao.presidentes[i].votos;
            PMaisVotado = eleicao.presidentes[i];
            empate=0;
        }
        else if(eleicao.presidentes[i].votos==maisvotos)
        {
            empate=1;
        }
    }
    printf("- PRESIDENTE ELEITO: ");
    if(empate==1)
    {
        printf("EMPATE. SERA NECESSARIO UMA NOVA VOTACAO\n");
    }
    else if(PMaisVotado.votos<eleicao.votosNulosPresidente+eleicao.votosBrancosPresidente)
    {
        printf("SEM DECISAO\n");
    }
    else
    {
        float percentualP;
        percentualP = CalculaPercentualVotos(PMaisVotado, eleicao.totalEleitores);
        ImprimeCandidato(GMaisVotado, percentualP);
    }

    //Ver qual governador ganhou
    empate=0;
    maisvotos=-1;
    for(i=0; i<eleicao.totalGovernadores ; i++)
    {
        if(eleicao.governadores[i].votos>maisvotos)
        {
            maisvotos=eleicao.governadores[i].votos;
            GMaisVotado = eleicao.governadores[i];
            empate=0;
        }
        else if(eleicao.governadores[i].votos==maisvotos)
        {
            empate=1;
        }
    }

    printf("- GOVERNADOR ELEITO: ");
    if(empate==1)
    {
        printf("EMPATE. SERA NECESSARIO UMA NOVA VOTACAO\n");
    }
    else if(GMaisVotado.votos<eleicao.votosBrancosGovernador+eleicao.votosNulosGovernador)
    {
        printf("SEM DECISAO\n");
    }
    else
    {
        float percentualg;
        percentualg = CalculaPercentualVotos(GMaisVotado, eleicao.totalEleitores);
        ImprimeCandidato(GMaisVotado, percentualg);
    }

    printf("- NULOS E BRANCOS: %d, %d", eleicao.votosNulosGovernador+eleicao.votosNulosPresidente , eleicao.votosBrancosPresidente+eleicao.votosBrancosGovernador);
}
