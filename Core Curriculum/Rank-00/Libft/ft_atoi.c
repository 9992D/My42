int	ft_atoi(const char *str)
{
	int	c;
	int	sign;
	int	result;

	c = 0;
	sign = 1;
	result = 0;
	while (str[c] == ' ' || str[c] == '\t' || str[c] == '\n' || str[c] == '\v'
		|| str[c] == '\f' || str[c] == '\r')
		c++;
	if (str[c] == '+' || str[c] == '-')
	{
		if (str[c] == '-')
			sign = -1;
		c++;
	}
	while (str[c] >= '0' && str[c] <= '9')
	{
		result = result * 10 + (str[c] - '0');
		c++;
	}
	return (result * sign);
}
