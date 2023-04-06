#pragma once
#include "application/setups/editor/commands/replace_whole_project_command.h"

void replace_whole_project_command::undo(editor_command_input in) {
	{
		/*
			We need to do this.
			That is because the original "after" is an autosave loaded directly from HDD.

			If we assigned it later on redo, and then rescanned for new resources on HDD again,
			they could potentially create different set of resource ids,
			therefore invalidating later commands in editor history.
		*/

		*after = in.setup.get_project();
	}

	in.setup.assign_project(*before);
}

void replace_whole_project_command::redo(editor_command_input in) {
	in.setup.assign_project(*after);
}
