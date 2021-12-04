namespace UnrealBuildTool.Rules
{
	public class BlueprintQuaternionLibrary : ModuleRules
	{
		public BlueprintQuaternionLibrary(ReadOnlyTargetRules Target) : base(Target)
		{

			PublicDependencyModuleNames.AddRange(
				new string[]
				{
					"Core",
					"CoreUObject",
					"Engine"
				}
			);
		}
	}
}
