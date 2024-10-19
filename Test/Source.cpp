#include <algorithm>
#include <iostream>
using namespace std;

struct FVector
{
    int X, Y, Z;
    FVector(int X, int Y, int Z) : X(X), Y(Y), Z(Z) {}
    FVector() : X(0), Y(0), Z(0) {}
};

struct FTransform
{
    FVector Location;
    FVector Rotation;
    FVector Scale;
    FTransform() : Location(FVector(0, 0, 0)), Rotation(FVector(0, 0, 0)), Scale(FVector(1, 1, 1)) {}
    void SetLocation(FVector Location) { this->Location = Location; }
    void SetRotation(FVector Rotation) { this->Rotation = Rotation; }
    void SetScale(FVector Scale) { this->Scale = Scale; }
};

class UObject
{
public:
};

class AActor : public UObject
{
public:
    FTransform Transform;

    FTransform& GetTransform() { return Transform; }
    
    FVector GetActorLocation() { return GetTransform().Location; }

    void SetActorLocation(FVector Location) { GetTransform().SetLocation(Location); }

    FVector GetActorRotation() { return GetTransform().Rotation; }

    void SetActorRotation(FVector Rotation) { GetTransform().SetRotation(Rotation); }
};

class AController : public AActor
{
public:
    
};

class ACharacter : public AActor
{
public:
    AController* Controller;

    AController* GetController() { return Controller; }

    void SetController(AController* Controller) { this->Controller = Controller;}

    void SetControllerRotation(FVector Rotation) { GetController()->SetActorRotation(Rotation); }
};

int main()
{
    ACharacter* Character = new ACharacter();
    AController* Controller = new AController();
    Character->SetController(Controller);
    Character->SetControllerRotation(FVector(1, 1, 1));
    cout << Character->GetController()->GetActorRotation().X << endl;
    Character->SetActorLocation(FVector(1000, 1000, 1000));
    cout << Character->GetActorLocation().X << endl;
    Character->GetController()->SetActorLocation(FVector(1000, 1000, 1000));
    cout << Character->GetController()->GetActorLocation().X << endl;

    AController* xControllerx = Character->GetController();
    xControllerx->SetActorRotation(FVector(123, 123, 123));
    cout << Character->GetController()->GetActorRotation().X << endl;
}