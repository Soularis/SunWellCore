
 
enum ForbiddenAreas
{
    ISLAND_2          = 2317,  // South Seas (Tanaris)
    GM_ISLAND           = 876    // GM Island
};
     
class gmislandsecurity : public PlayerScript
{
public:
	gmislandsecurity() : PlayerScript("gmislandsecurity") {}
     
    void OnUpdateZone(Player* player, uint32 newZone, uint32 newArea)
    {
        switch (newArea)
        {
            case ISLAND_2:
                // if Normal player is at GM Island CrossRoad GY
                if (player->GetSession()->GetSecurity() >= 1) // Or RBAC 'HasPermission(rbac::PERMISSION_NAME);'
                    return;
				player->TeleportTo(1, -591.534363, -2522.759521, 91.791000, 1.358702); // Crossroads GY
                break;
            case GM_ISLAND:
                // if Normal Player is at GM Teleport to Crossroads GY
                if (player->GetSession()->GetSecurity() >= 2) // Or RBAC 'HasPermission(rbac::PERMISSION_NAME);'
                    return;
				player->TeleportTo(1, -591.534363, -2522.759521, 91.791000, 1.358702); // Crossroads GY
                break;
        }
    }
};
     
void AddSC_gmislandsecurity()
{
    new gmislandsecurity();
}