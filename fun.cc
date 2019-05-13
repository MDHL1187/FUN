void SplitJob(const std::vector<std::string> &lsJobs, std::vector<std::string> &jobs, int nb_batch, int nb_total, bool clearPrevJobs = true, bool verbose = false)
{
	if (lsJobs.size() == 0 || nb_batch <= 0 || nb_total <= 0) // defensive
	{
		return;
	}
	if (clearPrevJobs)
	{
		jobs.clear();
	}
	if (nb_batch > nb_total)
	{
		nb_batch %= nb_total; // rotate; nb_batch will never be zero!
	}
	int nb_count = static_cast<int>(lsJobs.size());
	int n = (int)((double)nb_count / nb_total);
	int i = 0, j = 0;
	if (n == 0)
	{
		i = nb_batch - 1;
		j = i + 1;
		j = std::min(j, nb_count);
	}
	else
	{
		int d = nb_count - n * nb_total;
		if (nb_batch > 1)
		{
			int u = nb_batch - 1;
			if (d > 0)
			{
				if (nb_batch > d)
				{
					i = u * n + d;
				}
				else
				{
					i = u * n + u;
				}
			}
			else
			{
				i = u * n;
			}
		}
		
		if (d == 0)
		{
			j = nb_batch * n;
		}
		else
		{
			if (nb_batch >= d)
			{
				j = nb_batch * n + d;
			}
			else
			{
				j = nb_batch * n + nb_batch;
			}
		}
	}

	if (verbose)
	{
		std::cout << "\t\t>> [DEBUG MSG] count = " << nb_count << std::endl;
		std::cout << "\t\t>> [DEBUG MSG] n = " << n << std::endl;
		std::cout << "\t\t>> [DEBUG MSG] i = " << i << std::endl;
		std::cout << "\t\t>> [DEBUG MSG] j = " << j << std::endl;
		std::cout << "\t\t>> [DEBUG MSG] size = " << std::max(0, j - i) << std::endl;
	}
	for (; i < j; i++)
	{
		if (verbose)
		{
			std::cout << "\t\t>> [DEBUG MSG] Inserting an elment : " << (i + 1) << std::endl;
		}
		jobs.push_back(lsJobs[i]);
	}
}

auto main(int argc, char **argv) -> iHL_Int32 
{
	std::vector<std::string> lsJobs;
	for (int i = 0; i < 248; i++)
	{
		lsJobs.push_back(std::to_string(i));
	}
	std::vector<std::string> jobs;
	for (int i = 1; i < 11; i++)
	{
		std::cout << "\tSplitting jobs for " << i << " out of 40" << std::endl;
		SplitJob(lsJobs, jobs, i, 40, true, true);
	}
	SplitJob(lsJobs, jobs, 12, 79, true, true);
	return 0;
}