#pragma once

void local_search(std::vector<cidade>& cidades, std::vector<truck>& caminhao, int& custo_total, std::vector<int> visitas_p_familia, std::vector<int>  cidades_cada_familia, int n_family, int n_city, int& n_visitas, int n_veic)
{
	///quantidade de interacoes to local search
	int quant_n0, quant_n1, quant_tudo;
	quant_tudo = 4000;
	quant_n0 = 100;
	quant_n1 = 100;


	int custo_otimizado=custo_total;
	//////////////////recria os valores aux
	std::vector <cidade> cidades_aux;

	//criar copia cidade e veiculos na cidade_aux e caminhoes_aux
	std::vector <truck> caminhoes_aux;


	for (int jj = 0; jj < n_city; jj++)
	{
		cidades_aux.push_back({ });
		cidades_aux[jj] = cidades[jj];
	}

		// search N1(s) and obtain s*
		for (int i = 0; i < quant_n0;i++)
		{
			// recria o caminhão
			for (int j = 0; j <= n_veic; j++)
			{
				caminhoes_aux.push_back({ });
				for (int jj = 0; jj < n_visitas; jj++) // 
				{
					caminhoes_aux[n_veic].rota.push_back({ });
					caminhoes_aux[n_veic].rota[jj] = caminhao[j].rota[jj];
				}
			}

			troca_dentro_rota(caminhoes_aux, n_visitas);
			//gravar_caminhao(caminhoes_aux, n_veic, "line", n_visitas, n_city, cidades_aux, "2", "bayg29.tsp_4_1001_1001_2.txt");
			// testa e atualiza
			custo_otimizado = tempo_total_rota(cidades_aux, caminhoes_aux, n_visitas, n_veic);
			if (custo_total > custo_otimizado)
			{

				for (int i = 0; i < n_city; i++)
				{
					cidades[i] = cidades_aux[i];
				}

				custo_total = custo_otimizado;// tempo_total_rota(cidades_aux, caminhao, n_visitas, n_veic);
				//////////////////////atualiza  vetores
				for (int j = 0; j <= n_veic; j++)
				{
					caminhao[j].rota.push_back({ });
					for (int i = 0; i < n_visitas; i++) // 
					{
						caminhao[j].rota[i] = caminhoes_aux[n_veic].rota[i];
					}
				}

			}

		}

		// search N0(s*) and obtain s**
		for (int i = 0; i < quant_n1; i++)
		{
			// recria o caminhão
			for (int j = 0; j <= n_veic; j++)
			{
				caminhoes_aux.push_back({ });
				for (int jj = 0; jj < n_visitas; jj++) // 
				{
					caminhoes_aux[n_veic].rota.push_back({ });
					caminhoes_aux[n_veic].rota[jj] = caminhao[j].rota[jj];
				}
			}
			// recria as cidades
			for (int jj = 0; jj < n_city; jj++)
			{
				cidades_aux.push_back({ });
				cidades_aux[jj] = cidades[jj];
			}

			troca_fora_rota(caminhoes_aux, n_visitas, cidades_aux, n_city);
			// testa e atualiza
			custo_otimizado = tempo_total_rota(cidades_aux, caminhoes_aux, n_visitas, n_veic);
			if (custo_total > custo_otimizado)
			{
				custo_total = custo_otimizado;// tempo_total_rota(cidades_aux, caminhao, n_visitas, n_veic);
				/////////////////////atualiza  vetores
				for (int j = 0; j <= n_veic; j++)
				{
					caminhao[j].rota.push_back({ });
					for (int i = 0; i < n_visitas; i++) // 
					{
						caminhao[j].rota[i] = caminhoes_aux[n_veic].rota[i];
					}
				}
				for (int i = 0; i < n_city; i++)
				{
					cidades[i] = cidades_aux[i];
				}

			}

		}

		// search N1(s**) and obtain s***
		for (int i = 0; i < quant_n0; i++)
		{
			// recria o caminhão
			for (int j = 0; j <= n_veic; j++)
			{
				caminhoes_aux.push_back({ });
				for (int jj = 0; jj < n_visitas; jj++) // 
				{
					caminhoes_aux[n_veic].rota.push_back({ });
					caminhoes_aux[n_veic].rota[jj] = caminhao[j].rota[jj];
				}
			}

			troca_dentro_rota(caminhoes_aux, n_visitas);
			// testa e atualiza
			custo_otimizado = tempo_total_rota(cidades_aux, caminhoes_aux, n_visitas, n_veic);
			if (custo_total > custo_otimizado)
			{

				custo_total = custo_otimizado;// tempo_total_rota(cidades_aux, caminhao, n_visitas, n_veic);

				//////////////////////atualiza  vetores
				for (int j = 0; j <= n_veic; j++)
				{
					caminhao[j].rota.push_back({ });
					for (int i = 0; i < n_visitas; i++) // 
					{
						caminhao[j].rota[i] = caminhoes_aux[n_veic].rota[i];
					}
				}

			}

		}




}
