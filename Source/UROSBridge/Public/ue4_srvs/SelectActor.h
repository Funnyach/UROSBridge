#pragma once

#include "ROSBridgeSrv.h"



namespace ue4_srvs
{
	class SelectActor : public FROSBridgeSrv
	{
	public:
		SelectActor()
		{
			SrvType = TEXT("ue4_srvs/SelectActor");
		}

		class Request : public SrvRequest
		{
		private:
			FString ActorName;
					
		public:
			Request(){ }
			Request(FString InActorName)
				:
				ActorName(InActorName) { }
			
			
			// Getters 
			FString GetActorName() const { return ActorName; }
			
			
			// Setters 
			void SetActorName(FString InActorName) { ActorName = InActorName; }
			
			virtual void FromJson(TSharedPtr<FJsonObject> JsonObject) override
			{
				ActorName = JsonObject->GetStringField(TEXT("actor_name"));

			}
			
			virtual void FromBson(TSharedPtr<FBsonObject> BsonObject) override
			{
				ActorName = BsonObject->GetStringField(TEXT("actor_name"));

			}
			
			static Request GetFromJson(TSharedPtr<FJsonObject> JsonObject)
			{
				Request Req;
				Req.FromJson(JsonObject);
				return Req;
			}
			
			static Request GetFromBson(TSharedPtr<FBsonObject> BsonObject)
			{
				Request Req;
				Req.FromBson(BsonObject);
				return Req;
			}
			
			virtual FString ToString() const override
			{
									
				return TEXT("SelectActor::Request { actor_name = ") + ActorName +
					TEXT(" } ");

			}
			
			virtual TSharedPtr<FJsonObject> ToJsonObject() const
			{
				TSharedPtr<FJsonObject> Object = MakeShareable<FJsonObject>(new FJsonObject());

				Object->SetStringField(TEXT("actor_name"), ActorName);

				return Object;

			}
			
			virtual TSharedPtr<FBsonObject> ToBsonObject() const
			{
				TSharedPtr<FBsonObject> Object = MakeShareable<FBsonObject>(new FBsonObject());

				Object->SetStringField(TEXT("actor_name"), ActorName);

				return Object;

			}
		};
		
		class Response : public SrvResponse
		{
		private:
			bool Success;
			
			
		public:
			Response(){ }
			Response(bool InSuccess)
				:
				Success(InSuccess) { }
			
			
			// Getters 
			bool GetSuccess() const { return Success; }
			
			
			// Setters 
			void SetSuccess(bool InSuccess) { Success = InSuccess; }
			
			
			virtual void FromJson(TSharedPtr<FJsonObject> JsonObject) override
			{
				Success = JsonObject->GetBoolField(TEXT("success"));

			}
			
			virtual void FromBson(TSharedPtr<FBsonObject> BsonObject) override
			{
				Success = BsonObject->GetBoolField(TEXT("success"));

			}
			
			static Response GetFromJson(TSharedPtr<FJsonObject> JsonObject)
			{
				Response Resp;
				Resp.FromJson(JsonObject);
				return Resp;
			}
			
			static Response GetFromBson(TSharedPtr<FBsonObject> BsonObject)
			{
				Response Resp; 
				Resp.FromBson(BsonObject);
				return Resp;
			}			
			
			virtual FString ToString() const override
			{
									
				return TEXT("SelectActor::Response { success = ") + FString::FromInt(Success) +
					TEXT(" } ");

			}
			
			virtual TSharedPtr<FJsonObject> ToJsonObject() const
			{
				TSharedPtr<FJsonObject> Object = MakeShareable<FJsonObject>(new FJsonObject());

				Object->SetBoolField(TEXT("success"), Success);

				return Object;

			}
			
			virtual TSharedPtr<FBsonObject> ToBsonObject() const
			{
				TSharedPtr<FBsonObject> Object = MakeShareable<FBsonObject>(new FBsonObject());

				Object->SetBoolField(TEXT("success"), Success);

				return Object;

			}
		};
		
	};
	
}