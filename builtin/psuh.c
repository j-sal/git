#include "builtin.h"
#include "config.h"

int cmd_psuh(int argc, const char **argv, const char *prefix)
{
	const char *cfg_name;
	int i;

	printf(_("Another pony saying hello goes here!\n"));

	printf(Q_("Your args (there is %d):\n",
		  "Your args (there are %d):\n",
		  argc),
		argc);
	for (i = 0; i < argc; i++)
		printf("%d: %s\n", i, argv[i]);

	printf(_("Your current working directory:\n<top-level>%s%s\n"),
		prefix ? "/" : "", prefix ? prefix : "");

	git_config(git_default_config, NULL);
	if (git_config_get_string_tmp("user.name", &cfg_name) > 0)
		printf(_("No name is found in config\n"));
	else
		printf(_("Your name: %s\n"), cfg_name);

	return 0;
}
