#include "builtin.h"
#include "config.h"
#include "wt-status.h"
#include "commit.h"
#include "pretty.h"
#include "parse-options.h"

static const char * const psuh_usage[] = {
	N_("git psuh [<arg>...]"),
	NULL,
};

int cmd_psuh(int argc, const char **argv, const char *prefix)
{
	struct wt_status status;
	struct commit *c = NULL;
	struct strbuf commitline = STRBUF_INIT;
	const char *cfg_name;
	int i;

	struct option options[] = {
		OPT_END()
	};

	printf(_("'Psuh'?\n"
		 "Here's a Pony saying 'Uhm hello!' 		\n"
		      " ___________				\n"
		      "< uhm, hello >				\n"
		      " -----------				\n"
		      "        \\   n,,n			\n"
		      "         \\  (oo)\\\\_____		\n"
		      "            |__|\\\\      )\\\\		\n"
		      "                ||-----|| \\\\		\n"
		      "                ||     ||		\n"
		      "	^^^^^^^^^^^^^^^^^^^^			\n"
		      "				from nasamuffin's git\n"));

	argc = parse_options(argc, argv, prefix, options, psuh_usage, 0);

	printf(Q_("\nYour args (there is %d):\n",
		  "Your args (there are %d):\n",
		  argc),
		argc);
	for (i = 0; i < argc; i++)
		printf("%d: %s\n", i, argv[i]);

	printf(_("\nYour current working directory:\n<top-level>%s%s\n"),
		prefix ? "/" : "", prefix ? prefix : "");

	git_config(git_default_config, NULL);
	if (git_config_get_string_tmp("user.name", &cfg_name) > 0)
		printf(_("No name is found in config\n"));
	else
		printf(_("\nYour name: %s\n"), cfg_name);

	wt_status_prepare(the_repository, &status);
	git_config(git_default_config, &status);

	printf(_("\nYour current branch: %s\n"), status.branch);


	c = lookup_commit_reference_by_name("origin/master");

	if (c != NULL) {
		pp_commit_easy(CMIT_FMT_ONELINE, c, &commitline);
		printf(_("Current commit: %s\n\n"), commitline.buf);
	}

	return 0;
}
